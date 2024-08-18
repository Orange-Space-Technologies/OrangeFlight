#include <Arduino.h>
#include <vector>

#include "const.h"
#include "config.h"

#include "telemetry/telemetry.h"
#include "hardware/gpio.h"
#include "tasks/tasks.h"
#include "state/state.h"
#include "enums.h"


std::vector<Task> tasks; // will be used by the scheduler on core1
V_STATE v_state = V_STATE::INIT; // Vehicle state global variable
StateVector state_vector;
