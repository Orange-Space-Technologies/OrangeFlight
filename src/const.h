#define ORANGEFLIGHT_VERSION "0.1.0"

#define CHECK_CORE0() if(state_core0.p_state!=P_STATE::INIT){Serial.println("Error initializing core0, error message:");Serial.println(state_core0.error_message);Serial.println("Exiting...");return;}