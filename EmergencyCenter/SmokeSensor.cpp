#include "SmokeSensor.h"
#include <iostream>

// class SmokeSensor : public Sensor {
// private:
//     float smokeConcentration;

// public:
//     // Constructor
//     SmokeSensor(SensorZone zone, std::string vendor, float smokeConcentration);

//     // Implement getSensorType method
//     std::string getSensorType() const override;

//     // Additional functionality for smoke sensors
//     void sendAlarm(int threshold);

//     // Implement test method
//     void test() override;
// };


// Constructor for SmokeSensor
SmokeSensor::SmokeSensor(SensorZone* zone, std::string vendor, float gasConcentration)
    : Sensor(zone, vendor), smokeConcentration(gasConcentration) {
    // Additional initialization can be done here if needed
}

// Overriding getSensorType function
std::string SmokeSensor::getSensorType() const {
    return "SmokeSensor";
}

// Method to send an alarm if the gas concentration exceeds a threshold
void SmokeSensor::sendAlarm(float threshold) {
    if (smokeConcentration > threshold) {
        std::cout << "SmokeSensor: smoke concentration exceeds threshold! Sending alarm!" << std::endl;
        alarm();  // This calls the base class `Sensor`'s alarm method
    }
}


void SmokeSensor::test() {
    if (getStatus() == SensorStatus::Active) {
        std::cout << "Testing SmokeSensor (ID: " << getID() << ")..." << std::endl;
        sendAlarm(0);
    } else {
        std::cout << "Test not valid for SmokeSensor (ID: " << getID() << ") because it is not activated." << std::endl;
    }

}

