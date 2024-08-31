#pragma once

// Config file specifing everything from which GPIO pins to use to the weight and center of gravity and inertia of the rocket

// Pyro pins
#define PIN_PYRO_1_FIRE 2
#define PIN_PYRO_2_FIRE 3
// #define PIN_PYRO_3_FIRE 3
// #define PIN_PYRO_4_FIRE 4

// #define PIN_PYRO_1_CONTINUITY 5
// #define PIN_PYRO_2_CONTINUITY 6
// #define PIN_PYRO_3_CONTINUITY 7
// #define PIN_PYRO_4_CONTINUITY 8

// Sensors
#define SENSORS_I2C_BUS Wire
#define SENSORS_I2C_SCL 17
#define SENSORS_I2C_SDA 16

// Radio UART
#define RADIO_UART Serial1 // UART0 is Serial1, UART1 is Serial2
#define RADIO_FIFO_SIZE 128
#define RADIO_BAUD 9600
#define RADIO_TX_PIN 0
#define RADIO_RX_PIN 1
