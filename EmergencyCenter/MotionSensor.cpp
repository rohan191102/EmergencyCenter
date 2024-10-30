#include "MotionSensor.h"
#include <iostream>

MotionSensor::MotionSensor(SensorZone* zone, std::string vendor, float sensitivity)
    : Sensor(zone, vendor), sensitivity(sensitivity) {}

std::string MotionSensor::getSensorType() const {
    return "MotionSensor";
}

void MotionSensor::sendAlarm(int threshold) {
    if (sensitivity > threshold) {
        std::cout << "MotionSensor: Sensitivity exceeds threshold! Sending alarm..." << std::endl;
        alarm();
    } else {
        std::cout << "MotionSensor: Sensitivity is within safe levels." << std::endl;
    }
}

void MotionSensor::test() {
    if (getStatus() == SensorStatus::Active) {
        std::cout << "Testing MotionSensor (ID: " << getID() << ")..." << std::endl;
        sendAlarm(0);
    } else {
        std::cout << "Test not valid for MotionSensor (ID: " << getID() << ") because it is not activated." << std::endl;
    }
}
