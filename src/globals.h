#pragma once

#include "const.h"
#include "config.h"

#include "structs.h"

#include "tasks/tasks.h"
#include "logging/logging.h"
#include "hardware/sensors.h"
#include "hardware/gpio.h"
#include "hardware/pyro.h"

#include "state/v_state.h"
#include "state/p_state.h"
#include "state/state_vector.h"

std::vector<Task> tasks; // will be used by the scheduler on core1
V_STATE v_state = V_STATE::INIT; // Vehicle state global variable

// Rocket physical state
StateVector state_vector;
int8_t temperature = 0;
double max_altitude = 0.0;

// Core states
CORE_STATE state_core0 = {P_STATE::INIT, "", false, 0};
CORE_STATE state_core1 = {P_STATE::INIT, "", false, 0};

// Contro loop timing
unsigned long loop_start_time;
unsigned long loop_duration;

// Automatically calculated stuff, DONT TOUCH
#define GET_TIME() (millis() / MILLIS_DIVIDER) // Dont touch this
#define CONTROL_LOOP_PERIOD (1000/CONTROL_LOOP_HZ) // automatically calculated, DONT TOUCH THIS