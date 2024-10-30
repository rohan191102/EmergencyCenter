#include "SensorZone.h"
#include "Sensor.h"
#include <iostream>
#include <algorithm>

SensorZone::SensorZone(int id, const std::string& description)
    : sensorZoneID(id), zoneDescription(description) {}


void SensorZone::addComponent(const std::shared_ptr<SensorComponent>& component) {  // again why ref works?
    if (component) {
        components.push_back(component);
    }
}

void SensorZone::removeComponent(const std::shared_ptr<SensorComponent>& component) {
    components.erase(
        std::remove(components.begin(), components.end(), component),
        components.end()
        );
}

std::vector<std::shared_ptr<SensorComponent>> SensorZone::getAllSensorComponents() const {
    return components;
}

void SensorZone::activate() {
    std::cout << "Activating Sensor Zone " << sensorZoneID << std::endl;
    for (const auto& component : components) {
        component->activate();
    }
}

void SensorZone::deactivate() {
    std::cout << "Deactivating Sensor Zone " << sensorZoneID << std::endl;
    for (const auto& component : components) {
        component->deactivate();
    }
}

void SensorZone::test() {
    std::cout << "Testing Sensor Zone " << sensorZoneID << " - " << zoneDescription << std::endl;
    for (const auto& component : components) {
        component->test();  // This calls `test()` on both sensors and subzones.
    }
}


int SensorZone::getID() const {
    return sensorZoneID;
}

std::vector<std::shared_ptr<Sensor>> SensorZone::getAllSensors() const {
    std::vector<std::shared_ptr<Sensor>> sensors;
    for (const auto& component : components) {
        // cast the component to a sensor
        // we are not sure the ptr as param is a sensor or sensorZone, bcs components ptr stores both sensor ptr & location ptr
        // diffrent ptr has different processing
        if (auto sensor = std::dynamic_pointer_cast<Sensor>(component)) {
            sensors.push_back(sensor);
        }
        // If it's a zone, get all of its sensors
        else if (auto subZone = std::dynamic_pointer_cast<SensorZone>(component)) {
            auto subZoneSensors = subZone->getAllSensors();
            sensors.insert(sensors.end(), subZoneSensors.begin(), subZoneSensors.end());
        }
    }
    return sensors;
}

std::string SensorZone::getDescription() const {
    return zoneDescription;
}

std::vector<std::shared_ptr<Sensor>> SensorZone::getAllSensorsSortedByID() const {
    auto sensors = getAllSensors();  // get all sensors first, then sort them out according to their id
    std::sort(sensors.begin(), sensors.end(),
              [](const std::shared_ptr<Sensor>& a, const std::shared_ptr<Sensor>& b) {
                  return a->getID() < b->getID();
              });
    return sensors;
}

std::vector<std::shared_ptr<Sensor>> SensorZone::getSensorsByType(const std::string& sensorType) const {
    std::vector<std::shared_ptr<Sensor>> sensorsByType;
    for (const auto& component : components) {
        // Check if the component is a Sensor
        if (auto sensor = std::dynamic_pointer_cast<Sensor>(component)) {
            if (sensor->getSensorType() == sensorType) {
                sensorsByType.push_back(sensor);
            }
        }
        // If it's a SensorZone, retrieve sensors from the subzone
        else if (auto subZone = std::dynamic_pointer_cast<SensorZone>(component)) {
            auto subZoneSensors = subZone->getSensorsByType(sensorType);
            sensorsByType.insert(sensorsByType.end(), subZoneSensors.begin(), subZoneSensors.end());
        }
    }
    return sensorsByType;
}

std::vector<std::shared_ptr<Sensor>> SensorZone::getSensorsByVendor(const std::string& vendor) const {
    std::vector<std::shared_ptr<Sensor>> sensorsByVendor;
    for (const auto& component : components) {
        // Check if the component is a Sensor
        if (auto sensor = std::dynamic_pointer_cast<Sensor>(component)) {
            if (sensor->getVendor() == vendor) {
                sensorsByVendor.push_back(sensor);
            }
        }
        // If it's a SensorZone, retrieve sensors from the subzone
        else if (auto subZone = std::dynamic_pointer_cast<SensorZone>(component)) {
            auto subZoneSensors = subZone->getSensorsByVendor(vendor);
            sensorsByVendor.insert(sensorsByVendor.end(), subZoneSensors.begin(), subZoneSensors.end());
        }
    }
    return sensorsByVendor;
}

std::vector<std::shared_ptr<Sensor>> SensorZone::getSensorsActiveAtTime(float time) const {
    std::vector<std::shared_ptr<Sensor>> activeSensors;
    for (const auto& component : components) {
        // Check if the component is a Sensor
        if (auto sensor = std::dynamic_pointer_cast<Sensor>(component)) {
            // Check if the sensor is active at the specified time
            if (sensor->isActiveAtTime(time)) {
                activeSensors.push_back(sensor);
            }
        }
        // If it's a SensorZone, retrieve active sensors from the subzone
        else if (auto subZone = std::dynamic_pointer_cast<SensorZone>(component)) {
            auto subZoneActiveSensors = subZone->getSensorsActiveAtTime(time);
            activeSensors.insert(activeSensors.end(), subZoneActiveSensors.begin(), subZoneActiveSensors.end());
        }
    }
    return activeSensors;
}

std::vector<std::shared_ptr<Sensor>> SensorZone::getSensorsByZone(const SensorZone& zone) const {
    std::vector<std::shared_ptr<Sensor>> sensorsInZone;
    for (const auto& sensor : zone.getAllSensors()) {
        sensorsInZone.push_back(sensor);
    }
    return sensorsInZone;
}

void SensorZone::testZoneByID(int zoneID) {
    if (sensorZoneID == zoneID) {
        std::cout << "Testing all sensors in Zone ID: " << zoneID << " - " << zoneDescription << std::endl;
        test(); // Calls the `test` function for the current zone.
    } else {
        for (const auto& component : components) {
            // Check if the component is a sub-zone.
            if (auto subZone = std::dynamic_pointer_cast<SensorZone>(component)) {
                subZone->testZoneByID(zoneID); // Recursively call for sub-zones.
            }
        }
    }
}

std::shared_ptr<SensorZone> SensorZone::findZoneByName(const std::string& name) const {
    if (this->zoneDescription == name) {
        return std::shared_ptr<SensorZone>(const_cast<SensorZone*>(this), [](SensorZone*) {});
    }

    for (const auto& component : components) {
        if (auto subZone = std::dynamic_pointer_cast<SensorZone>(component)) {
            auto result = subZone->findZoneByName(name);
            if (result) return result;
        }
    }
    return nullptr;
}

SensorZone& SensorZone::operator++() {
    std::cout << "Activating all sensors in " << zoneDescription << "using ++ operator \n";
    this->activate();
    return *this;
}


