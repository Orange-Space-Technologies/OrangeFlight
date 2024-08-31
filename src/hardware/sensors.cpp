#include "sensors.h"

void initSensors() {
    // Sensor specific functions are called from here
    initIMU();
    initBarometer();
    initGPS();
    initRadio();
}

void processSensors() {
    imu::Vector<3> imu_acceleration = sensor_imu.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
    imu::Quaternion imu_attitude = sensor_imu.getQuat();
    state_vector.update(imu_acceleration);
    state_vector.updateAttitude(imu_attitude);
    temperature = sensor_imu.getTemp();
}

void initIMU() {
    sensor_imu = Adafruit_BNO055(55, 0x28, &SENSORS_I2C_BUS);
}

void initBarometer() {
    // Initialize the BMP280 barometer here
}

void initGPS() {
    // Initialize the <random> GPS module here
}

void initRadio() {
    RADIO_UART.setTX(RADIO_TX_PIN);
    RADIO_UART.setRX(RADIO_RX_PIN);
    RADIO_UART.setFIFOSize(RADIO_FIFO_SIZE);
    RADIO_UART.begin(RADIO_BAUD);
    while (!RADIO_UART) delay(10); // Wait for serial port to open
}