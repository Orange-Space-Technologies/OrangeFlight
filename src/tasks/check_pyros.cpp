#include "check_pyros.h"

u8_t streamer_fired_times = 0;
bool main_fired = false;

void task_check_pyros() {
    if (main_fired) {return;}

    if (PYRO_STREAMER_FIRED && PYRO_STREAMER_CONTINUITY_CHECK()) { // If pyro fired but continuity check is ok (pyro is still connected, did not fire)
        if (streamer_fired_times > 3) {
            log_event("[CHECK TASK] Pyro 1 continuity check failed, pyro 1 fired more than 3 times, firing main pyro");
            main_fired = true;
            PYRO_FIRE_MAIN();
            return;
        }
        log_event("[CHECK TASK] Pyro 1 continuity check failed, firing pyro 1 again");
        PYRO_FIRE_STREAMER();
        streamer_fired_times++;
    }
}