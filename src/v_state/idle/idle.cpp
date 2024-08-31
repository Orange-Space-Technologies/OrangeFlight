#include "idle.h"

imu::Vector<3> imu_acceleration;
StateVector temp_state_vector;

unsigned long idle_start_time = 0;

void v_state_idle() { // If no movement for a certain time, switch to PAD_IDLE
    imu_acceleration = sensor_imu.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);

    // Calculate movement for 1 second
    if (idle_start_time == 0 || GET_TIME() - idle_start_time > PAD_IDLE_TIME_NEEDED) {
        if (temp_state_vector.position.magnitude() < PAD_IDLE_MOVEMENT_TRESHOLD) {
            v_state_change(&v_state, V_STATE::PAD_IDLE);
            return;
        }
        idle_start_time = GET_TIME();
        temp_state_vector = StateVector();
    }

    temp_state_vector.update(imu_acceleration);
}