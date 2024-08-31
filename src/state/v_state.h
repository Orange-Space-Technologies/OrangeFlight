#pragma once

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

void v_state_change(V_STATE *state, V_STATE new_state); // Function to change the vehicle state