# My Temperature Sensors Library for Arduino

This library provides a simple way to interface with different types of temperature sensors, including NTC, PTC, KTY, PT100, and PT1000 sensors. The library supports configurable parameters such as reference voltage, beta constant (for NTC/PTC), temperature coefficient (for PT100/PT1000), and correction factors (for KTY).

## Installation

1. Download the `My_temperature` folder.
2. Copy the `My_temperature` folder to your Arduino libraries directory (`Documents/Arduino/libraries`).
3. Open the Arduino IDE and restart it.

## Example Sketch

The example sketch (`example.ino`) demonstrates how to read temperatures from various sensors. Make sure to connect your sensors to the appropriate analog input pins on the Arduino.

### Pin Definitions:

- **NTC** sensor is connected to **A0**
- **PTC** sensor is connected to **A1**
- **PT100** sensor is connected to **A2**
- **PT1000** sensor is connected to **A3**
- **KTY** sensor is connected to **A4**

## Sensor Parameters

Each sensor has parameters that can be configured:
- **Beta constant** for NTC and PTC sensors
- **Temperature coefficient** for PT100 and PT1000 sensors
- **Correction factor** for KTY sensors

Example configuration for sensors:

```cpp
ntcSensor.setBeta(3950);  // Beta value for NTC
ptcSensor.setBeta(3500);  // Beta value for PTC
pt100Sensor.setTemperatureCoefficient(0.00385);  // Temperature coefficient for PT100
pt1000Sensor.setTemperatureCoefficient(0.00385); // Temperature coefficient for PT1000
ktySensor.setKtyCorrectionFactor(1.1);  // Correction factor for KTY
