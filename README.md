# Smart Plant Care Monitor

An Arduino Uno project that monitors a simulated soil-moisture level and turns on an LED alert when the soil is too dry. The project is built with PlatformIO and simulated in Wokwi.

## Features

- Reads an analog input on A0
- Displays the raw reading, estimated moisture percentage, and status in the Serial Monitor
- Turns on a red LED when the estimated moisture level is below 35%
- Turns the LED off when the level is 35% or higher

## Components

- Arduino Uno
- Potentiometer, used in Wokwi to simulate the soil-moisture sensor
- Red LED
- 220 Ω resistor

## Connections

| Component pin | Arduino Uno |
|---|---|
| Potentiometer VCC | 5V |
| Potentiometer GND | GND |
| Potentiometer SIG | A0 |
| LED and resistor | D7, in series |
| LED cathode | GND |

## How it works

The potentiometer changes the analog value read by the Arduino. The program converts that reading to an estimated percentage. Below 35%, the Serial Monitor displays **DRY - water needed** and the LED turns on. At 35% or higher, it displays **OK** and turns the LED off.

## Run the simulation

1. Open the project in VS Code with PlatformIO and Wokwi available.
2. Build the Arduino Uno project with PlatformIO.
3. Start the Wokwi simulation.
4. Open the Serial Monitor at 9600 baud.
5. Turn the potentiometer to change the simulated moisture level and observe the status and LED.

> **Note:** The potentiometer is only a simulation control. A physical soil-moisture sensor needs to be calibrated because its readings vary by sensor and soil conditions.
