#include <Arduino.h>

#include "config.h"

#include "hardware/gpio.h"

void initGPIO() {
    initPyros();
    // Also set up the UART bus, I2C bus, etc. for all the sensors
    
}

void initPyros() {
    pinMode(PIN_PYRO_1_FIRE, OUTPUT);
    pinMode(PIN_PYRO_2_FIRE, OUTPUT);
    pinMode(PIN_PYRO_3_FIRE, OUTPUT);
    pinMode(PIN_PYRO_4_FIRE, OUTPUT);

    pinMode(PIN_PYRO_1_CONTINUITY, INPUT);
    pinMode(PIN_PYRO_2_CONTINUITY, INPUT);
    pinMode(PIN_PYRO_3_CONTINUITY, INPUT);
    pinMode(PIN_PYRO_4_CONTINUITY, INPUT);
}

void initSensors() {
    // Sensor specific functions are called from here
    initIMU();
    initBarometer();
    initGPS();
}

void initIMU() {
    // Initialize the BNO055 IMU here
}

void initBarometer() {
    // Initialize the BMP280 barometer here
}

void initGPS() {
    // Initialize the <random> GPS module here
}