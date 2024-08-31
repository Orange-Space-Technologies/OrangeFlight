#pragma once

#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#include "config.h"
#include "globals.h"

Adafruit_BNO055 sensor_imu;

void initSensors(); // Initializes all sensors, will also be called in src/main.cpp by the setup function

// Sensor specific initialization functions, will be called by initSensors()
void initIMU(); // Initializes the BNO055 IMU
void initBarometer(); // Initializes the BMP280 barometer
void initGPS(); // Initializes the GPS module
void initRadio(); // Inizializes the radio module (sets up UART)

void processSensors(); // Processes all sensor data, will be called in the main loop