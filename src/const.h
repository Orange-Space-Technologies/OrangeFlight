#define ORANGEFLIGHT_VERSION "0.1.0"

#define CHECK_CORE0() if(state_core0.p_state!=P_STATE::INIT){log_event("Error initializing core0, error message:");uint buff_size = state_core0.error_message.length() + 1;char error_message[buff_size];state_core0.error_message.toCharArray(error_message, buff_size);log_event(error_message);;log_event("Exiting...");return;}