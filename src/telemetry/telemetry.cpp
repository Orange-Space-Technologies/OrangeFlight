#include "telemetry.h"

void sendTelemetry() {
    char telemetryPacket[] = "sth"; // replace this with actual telemetry data
    RADIO_UART.println(telemetryPacket);
}