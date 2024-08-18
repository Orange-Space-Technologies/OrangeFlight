#include <Arduino.h>
#include <vector>

#include "const.h"
#include "config.h"

#include "hardware/gpio.h"
#include "tasks/tasks.h"
#include "state/state.h"
#include "enums.h"

std::vector<Task> tasks; // will be used by the scheduler on core1
V_STATE v_state = V_STATE::INIT; // Vehicle state global variable
StateVector state_vector;

void setup() { //Setup on core0, will initialize hardware and tasks
    Serial.begin(115200);

    // Print the version of the firmware
    Serial.print("Starting OrangeFlight version ");
    Serial.print(ORANGEFLIGHT_VERSION);
    Serial.println("!");

    initGPIO();
    initSensors();
    state_vector = StateVector();
    v_state = V_STATE::IDLE;
}

void loop() { //Main loop on core0, will run the main control loop
    
}

void setup1() { //Setup on core1, will initialize the task system
    //tasks.push_back(Task(<function pointer>, <name>, <task period in ms>, <priority 0-50, default 10>));
    //tasks.push_back(Task(*gps_task, "GPS", 1000, 12));
}

void loop1() { //Main loop on core1, will run the task system
    runMostImportantTask(tasks);
}