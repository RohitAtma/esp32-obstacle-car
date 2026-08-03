# ESP32 Autonomous Obstacle-Avoiding Car

A 4-wheel self-driving car that navigates around obstacles on its own, 
built with an ESP32, an L298N motor driver, and an ultrasonic distance sensor.

## How it works
The car drives forward while the ultrasonic sensor continuously measures 
the distance ahead. When an object comes within 40cm, the car backs up 
and turns to avoid it, then continues — sensing, deciding, and driving 
in a constant loop.

## Build approach
- Logic and circuit prototyped in simulation first (Tinkercad), before 
  building on physical hardware
- Motors controlled through an L298N H-bridge driver (4 TT gear motors, 
  paired left/right)
- DIY frame built from scratch rather than a kit chassis
- Powered by a single 4xAA battery pack (motors via the driver, ESP32 
  via the driver's 5V regulator output)

## Status
- [x] Motor control working in simulation (forward/backward/turns)
- [x] Ultrasonic sensor reading distances
- [x] Obstacle-avoidance logic complete in simulation
- [x] Physical build (parts ordered)
- [x] Real-world testing and tuning

Built summer 2026 as a self-taught electronics project.
