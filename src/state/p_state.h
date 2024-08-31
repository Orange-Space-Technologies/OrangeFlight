enum class P_STATE { // Program state
    INIT, // Initialization and self-tests (program in setup() function)
    NORMAL, // Normal operation (program in loop() function)
    INIT_ERROR, // Error while init (sensors not found, self tests did not pass, etc.), we can try restarting the core, but that probably won't help
    RESTARTABLE_ERROR, // Error during normal operation, will trigger a restart routine on the other core which will restart the core with the error
    FATAL_ERROR, // Error during normal operation, good luck rocket
};