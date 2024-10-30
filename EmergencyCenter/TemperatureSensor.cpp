#include "TemperatureSensor.h"
#include <iostream>

TemperatureSensor::TemperatureSensor(SensorZone* zone, std::string vendor, float temp)
    : Sensor(zone, vendor), temp(temp) {}

std::string TemperatureSensor::getSensorType() const {
    return "TemperatureSensor";
}

void TemperatureSensor::sendAlarm(float threshold) {
    if (temp > threshold) {
        std::cout << "TemperatureSensor: Temperature exceeds threshold! Sending alarm!" << std::endl;
        alarm();
    }
}

void TemperatureSensor::setTemperatureThreshold(float threshold) {
    if (temp > threshold) {
        sendAlarm(threshold);
    }
}


void TemperatureSensor::test() {
    if (getStatus() == SensorStatus::Active) {
        std::cout << "Testing TemperatureSensor... (ID: " << getID() << ")..." << std::endl;
        sendAlarm(0);
    } else {
        std::cout << "Test not valid for TempSensor (ID: " << getID() << ") because it is not activated." << std::endl;
    }
}

