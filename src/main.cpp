#include "main.h"

void setup() { //Setup on core1, will initialize the task system
    rp2040.idleOtherCore();
    // Init serial port
    Serial.begin(115200);
    while (!Serial) delay(10); // Wait for serial port to open

    // Print the version of the firmware
    Serial.print("Starting OrangeFlight version ");
    Serial.print(ORANGEFLIGHT_VERSION);
    Serial.println(" on core0 !");

    Serial.println("Initializing sensors and GPIO...");
    initGPIO();
    initSensors();
    CHECK_CORE0();
    Serial.println("[OK] Sensors and GPIO initialized.");

    Serial.println("Initializing the task system...");
    Serial.println("Registering tasks...");
    //tasks.push_back(Task(<function pointer>, <name>, <task period in ms>, <priority 0-50, default 10>));
    //tasks.push_back(Task(*gps_task, "GPS", 1000, 12));
    CHECK_CORE0();
    Serial.println("[OK] Task system initialized.");
    
    if (state_core0.p_state != P_STATE::INIT) { // Init (or some other) error
        Serial.println("Error initializing core0, error message:");
        Serial.println(state_core0.error_message);
        Serial.println("Exiting...");
        return;
    }
    state_core0.p_state = P_STATE::NORMAL;
    rp2040.resumeOtherCore();
}

void loop() { //Main loop on core1, will run the task system
    runMostImportantTask(tasks);
}

void setup1() { //Setup on core0, will initialize hardware and tasks
    state_core1.p_state = P_STATE::INIT; // Reset core state, this core might have been reset by the other core after failure
    if (state_core1.was_restared) { // This core was restarted after an error
        // state_core1.restart_count++;
        Serial.println("Restarting core1 after an error, trying to recover...");
        Serial.print("Error message from core1: ");
        Serial.println(state_core1.error_message);
    }
    state_core1.error_message = "";

    state_vector = StateVector();
    v_state = V_STATE::IDLE;
    
    state_core1.p_state = P_STATE::NORMAL;
}

void loop1() { //Main loop on core0, will run the main control loop
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
}


