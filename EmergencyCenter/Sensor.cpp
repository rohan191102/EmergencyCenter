#include "Sensor.h"
#include <iostream>
#include "IDGen.h"

Sensor::Sensor(SensorZone* zone, std::string vendor)
    : zone(zone), vendor(vendor), status(SensorStatus::Inactive), startHour(0), endHour(24) {
    // according to proj description, sensor IDGen should be used in the sensor class
    this->sensorId = IDGenerator::getInstance().generateID();
}

int Sensor::getID() const {
    return sensorId;
}
SensorStatus Sensor::getStatus() const {
    return status;
}

std::string Sensor::getVendor() const {
    return vendor;
}

void Sensor::activate() {
    status = SensorStatus::Active;
    std::cout << "Sensor " << sensorId << " activated." << std::endl;
}

void Sensor::deactivate() {
    status = SensorStatus::Inactive;
    std::cout << "Sensor " << sensorId << " deactivated." << std::endl;
}

void Sensor::setActiveHours(float start, float end) {
    startHour = start;
    endHour = end;
}

float Sensor::getStartHour() const {
    return startHour;
}

float Sensor::getEndHour() const {
    return endHour;
}

bool Sensor::isActiveAtTime(float currentHour) const {
    return (currentHour >= startHour && currentHour <= endHour);
}

SensorZone* Sensor::getZone() const {
    return zone;
}

void Sensor::addActionStrategy(std::shared_ptr<ActionStrategy> strategy) {
    if (strategy) { // check if shared_ptr is valid
        actionStrategies.push_back(strategy);  // add a strategy to the vector
    }
}


void Sensor::trigger() {
    // const auto& == const std::shared_ptr<ActionStrategy>& here
    for (const auto& strategy : actionStrategies) {
        strategy->execute();
    }
}

void Sensor::alarm() {
    std::cout << "Sensor " << sensorId << " triggered an alarm!" << std::endl;
    trigger();
}

void Sensor::setStatus(SensorStatus newStatus) {
    status = newStatus;
}

Sensor& Sensor::operator++() { // after activating return the sensor that's updated
    activate();
    return *this;
}

Sensor& Sensor::operator--() {
    deactivate();
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Sensor& sensor) {
    os << "Sensor Information:\n"
       << "ID: " << sensor.sensorId << "\n"
       << "Type: " << sensor.getSensorType() << "\n"
       << "Vendor: " << sensor.vendor << "\n"
       << "Status: ";

    switch(sensor.status) {
    case SensorStatus::Active:
        os << "Active";
        break;
    case SensorStatus::Inactive:
        os << "Inactive";
        break;
    case SensorStatus::Testing:
        os << "Testing";
        break;
    case SensorStatus::Triggered:
        os << "Triggered";
        break;
    }

    os << "\nActive Hours: " << sensor.startHour << " - " << sensor.endHour << "\n"
       << "Location: " << sensor.zone->getDescription() << "\n";

    return os;
}
