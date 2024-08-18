# OrangeFlight

OrangeFlight is a rocket control software developed by Orange Space Technologies.  
It is designed for our own PCB designs, using the RPi Pico 2 as the main microcontroller.  
You can find the design here: https://github.com/otazelezny/Test-Avionic-Bay  

## Compiling
You need to use PlatformIO in order to compile this project.  
Clone this repo and then open the project in VSCode (or other IDE with PlatformIO support), wait for the project to fully download all dependencies.  
You can then use the PlatformIO tab in vscode and click Build under Project Tasks -> pico -> General. That will build a standard RPi Pico binary that you can then upload to the Pico.  

## Architecture

The RPi Pico is a dual-core microprocessor, we use both of the cores available.  

core0 (the main core) initializes all the GPIO pins and sensors on bootup, and then runs our simple task scheduler.  
The task scheduler runs tasks like receiving and decoding the GPS data, storing telemetry on the on-board flash chip, etc.  

core0 also intializes the second core (core1) on startup.  

core1 runs the main control loop.  
This is done so that core0 can monitor core1 and if core1 crashes, core0 can try to restart core1 and recover control.  
If this fails, core0 will start running a very simple recovery routine as a last resort to try to get the rocket to the ground safely.  