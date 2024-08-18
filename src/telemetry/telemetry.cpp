#include "telemetry.h"
#include "main.h"

void sendTelemetry() {
    char telemetryPacket[] = "sth"; // replace this with actual telemetry data
    RADIO_UART.write(telemetryPacket);
}