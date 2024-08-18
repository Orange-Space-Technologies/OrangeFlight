#include <Arduino.h>
#include <vector>

#include "tasks/tasks.h"

Task::Task(void (*functionArg)(void), String nameArg, ulong periodArg, uint priorityArg) {
    function = functionArg;
    name = nameArg;
    period = periodArg;
    priority = priorityArg;
    lastRun = 0;
};

Task::Task(void (*functionArg)(void), String nameArg, ulong periodArg) {
    function = functionArg;
    name = nameArg;
    period = periodArg;
    priority = 10;
    lastRun = 0;
}

void Task::run() {
    function();
}

int Task::getPriority() {
    ulong runIn = period - (millis() - lastRun);
    return runIn * priority * -1;
}

void runTasks(std::vector<Task> tasks) {
    // Do some magic here
}