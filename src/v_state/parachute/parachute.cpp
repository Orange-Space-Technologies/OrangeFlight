#include "parachute.h"

unsigned long nomove_start_time = 0;
imu::Vector<3> start_position;

unsigned long vel_start_time = 0;

void v_state_parachute() {
    processSensors();

    if (nomove_start_time == 0) {
        nomove_start_time = GET_TIME();
    }

    // Calculate movement for 1 second
    if (GET_TIME() - nomove_start_time > LANDED_TIME_NEEDED) {
        start_position = state_vector.position;
        imu::Vector<3> movement = state_vector.position - start_position;
        if (abs(movement.magnitude()) < LANDED_MOVEMENT_TRESHOLD) {
            v_state_change(&v_state, V_STATE::LANDED);
            return;
        }
        nomove_start_time = GET_TIME();
    }

    if (state_vector.velocity.magnitude() < LANDED_VELOCITY_TRESHOLD) {
        if (vel_start_time == 0) {
            vel_start_time = GET_TIME();
        } else {
            if (GET_TIME() - vel_start_time > LANDED_TIME_NEEDED) {
                v_state_change(&v_state, V_STATE::LANDED);
                return;
            }
        }
    }
}