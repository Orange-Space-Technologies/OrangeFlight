#include "main.h"

#include "tasks/check_core1.h"
#include "tasks/check_pyros.h"

void setup()
{ // Setup on core1, will initialize the task system
    rp2040.idleOtherCore();
    // Init serial port
    Serial.begin(115200);
    while (!Serial)
        delay(10); // Wait for serial port to open

    // Init the logging subsystem
    setup_logging();

    // Print the version of the firmware
    log_event("Starting OrangeFlight version ");
    log_event(ORANGEFLIGHT_VERSION);
    log_event(" on core0 !");

    log_event("Initializing sensors and GPIO...");
    initGPIO();
    initSensors();
    CHECK_CORE0();
    log_event("[OK] Sensors and GPIO initialized.");

    log_event("Initializing the task system...");
    log_event("Registering tasks...");
    // tasks.push_back(Task(<function pointer>, <name>, <task period in ms>, <priority 0-50, default 10>));
    // tasks.push_back(Task(*gps_task, "GPS", 1000, 12));
    
    // Register tasks
    tasks.push_back(Task(*task_check_core1, "Check core1", 500, 12));
    tasks.push_back(Task(*task_check_pyros, "Check pyros", 1000, 10));

    CHECK_CORE0();
    log_event("[OK] Task system initialized.");

    if (state_core0.p_state != P_STATE::INIT)
    { // Init (or some other) error
        log_event("Error initializing core0, error message:");
        
        uint buff_size = state_core0.error_message.length() + 1;
        char error_message[buff_size];
        state_core0.error_message.toCharArray(error_message, buff_size);
        log_event(error_message);
        log_event("Exiting...");
        return;
    }
    state_core0.p_state = P_STATE::NORMAL;
    rp2040.resumeOtherCore();
}

void loop()
{ // Main loop on core1, will run the task system
    runMostImportantTask(tasks);
}

void setup1()
{                                        // Setup on core0, will initialize hardware and tasks
    state_core1.p_state = P_STATE::INIT; // Reset core state, this core might have been reset by the other core after failure
    if (state_core1.was_restared)
    { // This core was restarted after an error
        // state_core1.restart_count++;
        log_event("Restarting core1 after an error, trying to recover...");
        log_event("Error message from core1: ");
        
        uint buff_size = state_core1.error_message.length() + 1;
        char error_message[buff_size];
        state_core1.error_message.toCharArray(error_message, buff_size);
        log_event(error_message);
    }
    state_core1.error_message = "";

    state_vector = StateVector();
    v_state = V_STATE::IDLE;

    state_core1.p_state = P_STATE::NORMAL;
}

void loop1()
{ // Main loop on core0, will run the main control loop
    loop_start_time = GET_TIME();

    switch (v_state)
    {
    case V_STATE::INIT:
        v_state_init();
        break;
    case V_STATE::IDLE:
        v_state_idle();
        break;
    case V_STATE::PAD_IDLE:
        v_state_pad_idle();
        break;
    case V_STATE::POWERED_ASCENT:
        v_state_powered_ascent();
        break;
    case V_STATE::COAST:
        v_state_coast();
        break;
    case V_STATE::DESCENT:
        v_state_descent();
        break;
    case V_STATE::PARACHUTE:
        v_state_parachute();
        break;
    case V_STATE::LANDED:
        v_state_landed();
        break;
    default:
        break;
    }

    sendTelemetry();

    if (state_core1.p_state != P_STATE::NORMAL)
    {
        log_event("Error in core1, error message:");

        uint buff_size = state_core1.error_message.length() + 1;
        char error_message[buff_size];
        state_core1.error_message.toCharArray(error_message, buff_size);
        log_event(error_message);
        
        for (;;) {delay(10);}
    }

    // Delay to keep the loop running at the desired frequency
    loop_duration = GET_TIME() - loop_start_time;
    if (loop_duration < CONTROL_LOOP_PERIOD)
    {
        delay(CONTROL_LOOP_PERIOD - loop_duration);
    }
}
