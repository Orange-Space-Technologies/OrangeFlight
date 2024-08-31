#include "v_state.h"

void v_state_change(V_STATE *state, V_STATE new_state) {
    if (*state >= new_state && !(new_state == V_STATE::IDLE && *state == V_STATE::PAD_IDLE)) {
        // Cannot set the state to a lower state (except from PAD_IDLE to IDLE)
        return;
    }
    *state = new_state;
}