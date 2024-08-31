#include "v_state.h"
#include "logging/logging.h"
#include <Arduino.h>

void v_state_change(V_STATE *state, V_STATE new_state) {
    if (*state >= new_state && !(new_state == V_STATE::IDLE && *state == V_STATE::PAD_IDLE)) {
        // Cannot set the state to a lower state (except from PAD_IDLE to IDLE)
        return;
    }

    char old_s = (int)*state + '0';
    char new_s = (int)new_state + '0';

    arduino::String message = "State change: O: ";
    message.concat(old_s);
    message.concat(", N: ");
    message.concat(new_s);

    size_t buff_size = message.length() + 1;
    char message_buff[buff_size];
    message.toCharArray(message_buff, buff_size);    

    log_event(message_buff);
    *state = new_state;
}