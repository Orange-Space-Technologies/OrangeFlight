enum class V_STATE { // Vehicle state
    INIT, // Initialization and self-tests
    IDLE, // System ready, rocket still not on the pad (pre-launch ready)
    PAD_IDLE, // System ready, rocket on the pad (detected by the accelerometer, no movement for a while -> switch to PAD_IDLE)
    POWERED_ASCENT, // Launch, rocket is powered by the motor
    COAST, // Rocket is coasting, no power (burnout)
    DESCENT, // Apogee, rocket is now descending, no power
    PARACHUTE, // Parachute is deployed
    LANDED, // Rocket has landed
};

enum class P_STATE { // Program state
    INIT, // Initialization and self-tests (program in setup() function)
    NORMAL, // Normal operation (program in loop() function)
    INIT_ERROR, // Error while init (sensors not found, self tests did not pass, etc.), we can try restarting the core, but that probably won't help
    RESTARTABLE_ERROR, // Error during normal operation, will trigger a restart routine on the other core which will restart the core with the error
    FATAL_ERROR, // Error during normal operation, good luck rocket
};