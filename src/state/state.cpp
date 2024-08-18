#include "state.h"
#include "imumaths.h"

void StateVector::update(imu::Vector<3> acceleration) {
    ulong now = millis();
    double delta_time = (now - lastUpdateTime) / 1000;
    velocity = velocity + (acceleration * delta_time);
    position = position + (velocity * delta_time);
    lastUpdateTime = now;
}

void StateVector::updateAttitude(imu::Quaternion attitudeArg) {
    attitude = attitudeArg;
}

// Constructor
StateVector::StateVector() {
    lastUpdateTime = millis();
    attitude = imu::Quaternion(0,0,0,0);
    velocity = imu::Vector<3>(0,0,0);
    position = imu::Vector<3>(0,0,0);
}