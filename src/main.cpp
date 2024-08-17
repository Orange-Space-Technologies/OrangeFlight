#include <Arduino.h>

#include "const.h"
#include "config.h"

#include "hardware/gpio.h"

void setup() { //Setup on core0, will initialize hardware and tasks
  Serial.begin(115200);

  // Print the version of the firmware
  Serial.print("Starting OrangeFlight version ");
  Serial.print(ORANGEFLIGHT_VERSION);
  Serial.println("!");

  initGPIO();
  initSensors();
}

void loop() { //Main loop on core0, will run the main control loop
  
}

void setup1() { //Setup on core1, will initialize the task system
  //addTask(<function pointer>, <task name>, <task period in ms / other criteria>);
  std::vector<Task> tasks;
}

void loop1() { //Main loop on core1, will run the task system
  runTasks(); 
}