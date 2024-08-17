void initGPIO(); // This function will be called in src/main.cpp by the setup function

// All the following functions will be called by initGPIO()

void initPyros(); // Inizializes pyro channels and continuity checks

void initSensors(); // Initializes all sensors, will also be called in src/main.cpp by the setup function

// Sensor specific initialization functions, will be called by initSensors()
void initIMU(); // Initializes the BNO055 IMU
void initBarometer(); // Initializes the BMP280 barometer
void initGPS(); // Initializes the GPS module