#include "hardware/gpio.h"

void initGPIO() {
    initPyros();
    // Also set up the UART bus, I2C bus, etc. for all the sensors
    
}

void initPyros() {
    pinMode(PIN_PYRO_1_FIRE, OUTPUT);
    pinMode(PIN_PYRO_2_FIRE, OUTPUT);
    // pinMode(PIN_PYRO_3_FIRE, OUTPUT);
    // pinMode(PIN_PYRO_4_FIRE, OUTPUT);

    // pinMode(PIN_PYRO_1_CONTINUITY, INPUT);
    // pinMode(PIN_PYRO_2_CONTINUITY, INPUT);
    // pinMode(PIN_PYRO_3_CONTINUITY, INPUT);
    // pinMode(PIN_PYRO_4_CONTINUITY, INPUT);
}