#ifndef MY_TEMPERATURE_H
#define MY_TEMPERATURE_H

#include <Arduino.h>

class MyTemperature {
public:
    // Constructor to set up pin, sensor type, and reference voltage
    MyTemperature(uint8_t pin, String type, float referenceVoltage);

    // Method to set sensor type
    void setSensorType(String type);

    // Methods to set reference resistance and voltage
    void setReferenceResistance(float resistance);
    void setReferenceVoltage(float voltage);

    // Methods to set specific parameters for different sensors
    void setBeta(float beta); // For NTC and PTC sensors
    void setKtyCorrectionFactor(float factor); // For KTY sensor
    void setTemperatureCoefficient(float coeff); // For PT100 and PT1000 sensors

    // Method to read temperature from the sensor
    float readTemperature();

private:
    uint8_t _pin;
    String _sensorType;
    float _referenceResistance;
    float _referenceVoltage;
    float _beta;
    float _ktyCorrectionFactor;
    float _temperatureCoefficient;

    // Helper methods for temperature calculations
    float calculateNTCTemperature();
    float calculatePTCTemperature();
    float calculateKTYTemperature();
    float calculatePT100Temperature();
    float calculatePT1000Temperature();
};

#endif
