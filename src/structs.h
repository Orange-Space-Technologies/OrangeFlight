#include <Arduino.h>

#include "enums.h"

struct CORE_STATE {
    P_STATE p_state;
    String error_message;
    P_STATE last_state;
    bool was_restared;
    uint restart_count;
};