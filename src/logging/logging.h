#pragma once

void setup_logging();

void setup_telemetry_log(); // Telemetry log, contains all the telemetry in a binary format
void setup_event_log(); // Event log, contains all the events in a human readable format

void log_telemetry_packet(const char message[]);
void log_event(const char message[]);