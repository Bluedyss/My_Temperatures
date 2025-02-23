#include <My_Temperature.h>

// Define the pins for each sensor
#define NTC_PIN A0       // Pin for the NTC sensor
#define PTC_PIN A1       // Pin for the PTC sensor
#define PT100_PIN A2     // Pin for the PT100 sensor
#define PT1000_PIN A3    // Pin for the PT1000 sensor
#define KTY_PIN A4       // Pin for the KTY sensor

// Create instances of the MyTemperature class for each sensor type
MyTemperature ntcSensor(NTC_PIN, "NTC", 5.0);       // 5V reference voltage for NTC
MyTemperature ptcSensor(PTC_PIN, "PTC", 3.3);       // 3.3V reference voltage for PTC
MyTemperature pt100Sensor(PT100_PIN, "PT100", 5.0); // 5V reference voltage for PT100
MyTemperature pt1000Sensor(PT1000_PIN, "PT1000", 3.3); // 3.3V reference voltage for PT1000
MyTemperature ktySensor(KTY_PIN, "KTY", 5.0);       // 5V reference voltage for KTY

void setup() {
    Serial.begin(9600);  // Start serial communication for debugging

    // Set sensor parameters
    ntcSensor.setBeta(3950);  // Beta value for NTC sensor
    ptcSensor.setBeta(3500);  // Beta value for PTC sensor
    pt100Sensor.setTemperatureCoefficient(0.00385);  // Coefficient for PT100
    pt1000Sensor.setTemperatureCoefficient(0.00385); // Coefficient for PT1000
    ktySensor.setKtyCorrectionFactor(1.1);  // Correction factor for KTY
    
    // Set voltage divider for sensors
    ntcSensor.setReferenceResistance(10000); // Reference resistance for NTC sensor (10kΩ typical)
    ptcSensor.setReferenceResistance(10000); // Reference resistance for PTC sensor (10kΩ typical)
    pt100Sensor.setReferenceResistance(100);  // Reference resistance for PT100 sensor (100Ω typical)
    pt1000Sensor.setReferenceResistance(1000); // Reference resistance for PT1000 sensor (1000Ω typical)
    ktySensor.setReferenceResistance(10000);  // Reference resistance for KTY sensor (10kΩ typical)

}

void loop() {
    // Read and print the temperature from each sensor type
    Serial.print("NTC Temperature: ");
    Serial.print(ntcSensor.readTemperature());
    Serial.println(" °C");

    Serial.print("PTC Temperature: ");
    Serial.print(ptcSensor.readTemperature());
    Serial.println(" °C");

    Serial.print("PT100 Temperature: ");
    Serial.print(pt100Sensor.readTemperature());
    Serial.println(" °C");

    Serial.print("PT1000 Temperature: ");
    Serial.print(pt1000Sensor.readTemperature());
    Serial.println(" °C");

    Serial.print("KTY Temperature: ");
    Serial.print(ktySensor.readTemperature());
    Serial.println(" °C");

    delay(1000);  // Wait for 1 second before reading again
}
