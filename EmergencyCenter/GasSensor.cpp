#include "GasSensor.h"
#include <iostream>

// Constructor for GasSensor
GasSensor::GasSensor(SensorZone* zone, std::string vendor, float gasConcentration)
    : Sensor(zone, vendor), gasConcentration(gasConcentration) {
    // Additional initialization can be done here if needed
}

// Overriding getSensorType function
std::string GasSensor::getSensorType() const {
    return "GasSensor";
}

// Method to send an alarm if the gas concentration exceeds a threshold
void GasSensor::sendAlarm(float threshold) {
    if (gasConcentration > threshold) {
        std::cout << "GasSensor: Gas concentration exceeds threshold! Sending alarm!" << std::endl;
        alarm();  // This calls the base class `Sensor`'s alarm method
    }
    else{
        std::cout << "gasConc below TH" <<std::endl;
    }
}


void GasSensor::test() {
    if (getStatus() == SensorStatus::Active) {
        std::cout << "Testing GasSensor (ID: " << getID() << ")..." << std::endl;
        sendAlarm(0);
    } else {
        std::cout << "Test not valid for GasSensor (ID: " << getID() << ") because it is not activated." << std::endl;
    }
}
