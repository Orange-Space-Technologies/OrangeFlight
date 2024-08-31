#include "check_core1.h"
#include "globals.h"

void task_check_core1() {
    if (state_core1.p_state == P_STATE::FATAL_ERROR) {
        log_event("[CHECK TASK] Core1 in fatal error state, error message:");
        log_event("[CHECK TASK] ");
        
        uint buff_size = state_core1.error_message.length() + 1;
        char error_message[buff_size];
        state_core1.error_message.toCharArray(error_message, buff_size);
        log_event(error_message);
        
        log_event("[CHECK TASK] Good luck");
    }
    if (state_core1.p_state == P_STATE::RESTARTABLE_ERROR) {
        if (state_core1.restart_count > 3) {
            log_event("[CHECK TASK] Core1 in restartable error state, error message:");
            log_event("[CHECK TASK] ");
            
            uint buff_size = state_core1.error_message.length() + 1;
            char error_message[buff_size];
            state_core1.error_message.toCharArray(error_message, buff_size);
            log_event(error_message);

            log_event("[CHECK TASK] Restart count exceeded, entering fatal error state");
            state_core1.p_state = P_STATE::FATAL_ERROR;
            return;
        }
        log_event("[CHECK TASK] Core1 in restartable error state, error message:");
        
        uint buff_size = state_core1.error_message.length() + 1;
        char error_message[buff_size];
        state_core1.error_message.toCharArray(error_message, buff_size);
        log_event(error_message);

        log_event("[CHECK TASK] Restarting core1...");
        state_core1.was_restared = true;
        state_core1.restart_count++;
        rp2040.restartCore1();
        log_event("[CHECK TASK] Core1 restarted!");
        return;
    }
}