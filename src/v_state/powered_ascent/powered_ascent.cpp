#include "powered_ascent.h"

void v_state_powered_ascent() {
    processSensors();

    if (state_vector.acceleration.z() < 0) {
        v_state_change(&v_state, V_STATE::COAST);
    }
}