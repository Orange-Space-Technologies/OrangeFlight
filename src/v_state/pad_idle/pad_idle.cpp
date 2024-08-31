#include "pad_idle.h"

// Detect launch
void v_state_pad_idle() {
    processSensors();

    if (state_vector.acceleration.z() >= LAUNCH_TRESHOLD_ACCEL && state_vector.velocity.z() >= LAUNCH_TRESHOLD_VEL && state_vector.position.z() < LAUNCH_TRESHOLD_POS) {
        v_state_change(&v_state, V_STATE::POWERED_ASCENT);
    }
}