#pragma once

#include <Arduino.h>

typedef struct CORE_STATE {
    P_STATE p_state;
    String error_message;
    bool was_restared;
    uint restart_count;
} CORE_STATE;