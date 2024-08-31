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
    lastRun = GET_TIME();
    function();
}

int Task::getPriority() {
    ulong runIn = period - (GET_TIME() - lastRun);
    return runIn * priority * -1;
}

void runAllTasks(std::vector<Task> tasks) {
    int n = tasks.size();
    ulong priorities[n];
    for (int i = 0; i < n; i++) {
        priorities[i] = tasks[i].getPriority();
    }

    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < n; j++) {
            if (priorities[j] > priorities[max]) {
                max = j;
            }
        }
        tasks[max].run();
        priorities[max] = 0;
    }
}

void runMostImportantTask(std::vector<Task> tasks) {
    int n = tasks.size();
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i].getPriority() > tasks[max].getPriority()) {
            max = i;
        }
    }
    tasks[max].run();
}