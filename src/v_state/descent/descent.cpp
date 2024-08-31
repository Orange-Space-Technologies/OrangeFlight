#include "descent.h"

void v_state_descent() {
    processSensors();

    if (state_vector.position.z() < PARACHUTE_DEPLOYMENT_ALTITUDE) {
        FIRE_MAIN();
        v_state_change(&v_state, V_STATE::PARACHUTE);
    }
}