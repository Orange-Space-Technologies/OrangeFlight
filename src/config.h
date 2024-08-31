#pragma once

// Config file specifing everything from which GPIO pins to use to the weight and center of gravity and inertia of the rocket

// Time travel (xd)
#define MILLIS_DIVIDER 1

// Control loop
#define CONTROL_LOOP_HZ 100 // 10 ms

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

// IMU calibration
#define IMU_CALIBRATION_TIMEOUT 60000 // 60 seconds
#define IMU_CALIBRATION_STATUS_DELAY 10 // 10 miliseconds

#define MIN_IMU_GYRO_CALIBRATION 2 // Minimal needed calibration for the IMU
#define MIN_IMU_ACCEL_CALIBRATION 2
#define MIN_IMU_MAG_CALIBRATION 1

// STAGING

// Pad IDLE requirements
#define PAD_IDLE_TIME_NEEDED 5000 // 5 seconds
#define PAD_IDLE_MOVEMENT_TRESHOLD 0.1 // 10cm

// Launch treshold
#define LAUNCH_TRESHOLD 10 // 10 m/s^2