#include "tasks/tasks.h"

void Task::Task(void (*functionArg)(void), String nameArg, ulong periodArg, uint priorityArg) {
    function = functionArg;
    name = nameArg;
    period = periodArg;
    priority = priorityArg;
    lastRun = 0;
};

void Task::run() {
    function()
};

int Task::shouldRun() {
    runIn = period - (millis() - lastRun);
    return runIn * priority * -1;
};

void runTasks() {
    // Do some magic here
};