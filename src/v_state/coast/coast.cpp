#include "coast.h"

unsigned long apogee_start_time = 0;

void should_deploy_streamer() {
    #ifdef TWO_STAGE_RECOVERY
        FIRE_STREAMER();
    #endif
}

void v_state_coast() {
    processSensors();

    if (state_vector.velocity.z() < 0) {
        if (apogee_start_time == 0) {
            apogee_start_time = GET_TIME();
        } else {
            if (GET_TIME() - apogee_start_time > APOGEE_TIMEOUT) {
                should_deploy_streamer();
                v_state_change(&v_state, V_STATE::DESCENT);
                return;
            }
        }
    }

    double altitude = state_vector.position.z();
    if (altitude > max_altitude) {
        max_altitude = altitude;
    }

    if (altitude < max_altitude) {
        if (apogee_start_time == 0) {
            apogee_start_time = GET_TIME();
        } else {
            if (GET_TIME() - apogee_start_time > APOGEE_TIMEOUT) {
                should_deploy_streamer();
                v_state_change(&v_state, V_STATE::DESCENT);
                return;
            }
        }
    }

    if (max_altitude - altitude > MAX_ALTITUDE_DIFFERENCE) {
        should_deploy_streamer();
        v_state_change(&v_state, V_STATE::DESCENT);
    }
}