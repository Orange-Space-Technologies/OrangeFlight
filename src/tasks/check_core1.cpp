#include "check_core1.h"
#include "globals.h"

void check_core1_task() {
    if (state_core1.p_state == P_STATE::FATAL_ERROR) {
        Serial.println("[CHECK TASK] Core1 in fatal error state, error message:");
        Serial.print("[CHECK TASK] ");
        Serial.println(state_core1.error_message);
        Serial.println("[CHECK TASK] Good luck");
    }
    if (state_core1.p_state == P_STATE::RESTARTABLE_ERROR) {
        if (state_core1.restart_count > 3) {
            Serial.println("[CHECK TASK] Core1 in restartable error state, error message:");
            Serial.print("[CHECK TASK] ");
            Serial.println(state_core1.error_message);
            Serial.println("[CHECK TASK] Restart count exceeded, entering fatal error state");
            state_core1.p_state = P_STATE::FATAL_ERROR;
            return;
        }
        Serial.println("[CHECK TASK] Core1 in restartable error state, error message:");
        Serial.println(state_core1.error_message);
        Serial.println("[CHECK TASK] Restarting core1...");
        state_core1.was_restared = true;
        state_core1.restart_count++;
        rp2040.restartCore1();
        Serial.println("[CHECK TASK] Core1 restarted!");
        return;
    }
}