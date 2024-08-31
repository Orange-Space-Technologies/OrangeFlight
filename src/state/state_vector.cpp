#include "state_vector.h"

void StateVector::update(imu::Vector<3> acceleration_data) {
    ulong now = GET_TIME();
    double delta_time = (now - lastUpdateTime) / 1000;
    acceleration = acceleration_data;
    velocity = velocity + (acceleration * delta_time);
    position = position + (velocity * delta_time);
    lastUpdateTime = now;
}

void StateVector::updateAttitude(imu::Quaternion attitudeArg) {
    attitude = attitudeArg;
}

// Constructor
StateVector::StateVector() {
    lastUpdateTime = GET_TIME();
    attitude = imu::Quaternion(0,0,0,0);
    velocity = imu::Vector<3>(0,0,0);
    position = imu::Vector<3>(0,0,0);
}