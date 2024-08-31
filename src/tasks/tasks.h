#pragma once

#include <Arduino.h>
#include <vector>

class Task {
    private:
        void (*function)(void); // Function pointer to the task function that will be called
        ulong lastRun; // Last time the task was run in milliseconds
        uint priority; // Task priority. Bigger number - more priority. 0 - zero, 50 - highest, default 10
    public: // Public properties
        Task(void (*function)(void), String name, ulong period, uint priority); // Constructor with priority
        Task(void (*functionArg)(void), String nameArg, ulong periodArg); // Constructor without priority
        String name; // Task name
        ulong period; // Task period in milliseconds. Optimally, the function will be called every period milliseconds
        void run(); // Run the task function
        int getPriority(); // Get the task priority for the scheduler
};

void runTasks(std::vector<Task> tasks); // Run all tasks, will be called in src/main.cpp by loop1()
void runMostImportantTask(std::vector<Task> tasks); // Run the most important task, will be called in src/main.cpp by loop1()