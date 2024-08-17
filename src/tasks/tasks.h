#include <Arduino.h>

class Task {
    private:
        int id; // Numerical task ID
        void (*function)(void); // Function pointer to the task function that will be called
        ulong lastRun; // Last time the task was run in milliseconds
        uint priority; // Task priority. Bigger number - more priority. 0 - zero, 50 - highest, default 10
    public: // Public properties
        Task(void (*function)(void), String name, ulong period, uint priority); // Constructor
        String name; // Task name
        ulong period; // Task period in milliseconds. Optimally, the function will be called every period milliseconds
        void run(); // Run the task function
        int shouldRun(); // Check if the task should run now
};

void runTasks(); // Run tasks, will be called in src/main.cpp by loop1()