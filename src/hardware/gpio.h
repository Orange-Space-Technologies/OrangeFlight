#include <Arduino.h>

#include "config.h"

void initGPIO(); // This function will be called in src/main.cpp by the setup function

// All the following functions will be called by initGPIO()

void initPyros(); // Inizializes pyro channels and continuity checks