#pragma once

#include <Arduino.h>
#include <imumaths.h>

#include "globals.h"

class StateVector {
    public:
        StateVector();
        imu::Quaternion attitude;
        imu::Vector<3> acceleration; // in m/s^2
        imu::Vector<3> velocity; // in m/s
        imu::Vector<3> position; // in m
        ulong lastUpdateTime;
        void update(imu::Vector<3> acceleration);
        void updateAttitude(imu::Quaternion);
};