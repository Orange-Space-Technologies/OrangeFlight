#include <Arduino.h>
#include <vector>

#include "const.h"
#include "config.h"

#include "enums.h"
#include "structs.h"

#include "telemetry/telemetry.h"
#include "hardware/gpio.h"
#include "tasks/tasks.h"
#include "state/state.h"


std::vector<Task> tasks; // will be used by the scheduler on core1
V_STATE v_state = V_STATE::INIT; // Vehicle state global variable
StateVector state_vector;

// P_STATE p_state_core0 = P_STATE::INIT; // Program state global variable for core0
// P_STATE p_state_core1 = P_STATE::INIT; // Program state global variable for core1

CORE_STATE state_core0 = {P_STATE::INIT, "", false, 0};
CORE_STATE state_core1 = {P_STATE::INIT, "", false, 0};