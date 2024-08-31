#include "pad_idle.h"

void v_state_pad_idle() {
    processSensors();

    if (state_vector.acceleration.z() >= LAUNCH_TRESHOLD) {
        v_state_change(&v_state, V_STATE::POWERED_ASCENT);
    }
}