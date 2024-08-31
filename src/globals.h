#pragma once

#include "const.h"
#include "config.h"

#include "structs.h"

#include "tasks/tasks.h"

#include "state/v_state.h"
#include "state/p_state.h"
#include "state/state_vector.h"

#ifndef GLOBALS_H
#define GLOBALS_H 1

std::vector<Task> tasks; // will be used by the scheduler on core1
V_STATE v_state = V_STATE::INIT; // Vehicle state global variable
StateVector state_vector;

CORE_STATE state_core0 = {P_STATE::INIT, "", false, 0};
CORE_STATE state_core1 = {P_STATE::INIT, "", false, 0};

#endif