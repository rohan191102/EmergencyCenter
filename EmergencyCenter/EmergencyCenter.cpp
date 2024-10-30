#include "EmergencyCenter.h"
#include <algorithm> // for the std::remove function
#include <stdexcept> // for std::runtime_error
#include <iostream> // for std::cout


EmergencyCenter::EmergencyCenter(const std::string& centerName) : centerName(centerName) {}


void EmergencyCenter::addZone(const std::shared_ptr<SensorZone>& zone){
    zones.push_back(zone);
}

// "erase-remove idiom" pattern of cpp: the most common way to remove random pointers in a vector
void EmergencyCenter::removeZone(const std::shared_ptr<SensorZone>& zone){
    zones.erase(std::remove(zones.begin(), zones.end(), zone), zones.end());
}

std::weak_ptr<SensorZone> EmergencyCenter::getZoneByName(const std::string& name) {
    for (const auto& zone : zones) {
        if (zone->getDescription() == name) {
            return zone;
        }
    }
    throw std::runtime_error("Zone not found: " + name);
}


std::weak_ptr<SensorZone> EmergencyCenter::getZoneByID(int zoneID){
    for (const auto& zone : zones){
        if (zone->getID() == zoneID){
            return zone;
        }
    }
    throw std::runtime_error("Zone not found with ID: " + std::to_string(zoneID));

}

std::vector<std::shared_ptr<SensorZone>> EmergencyCenter::getZones() const {
    return zones;
}

void EmergencyCenter::activateAllSensors(){
    for (const auto& zone : zones){  //the reference needs to be const so the reference cannot be modified
        zone->activate();
    }
}

void EmergencyCenter::deactivateAllSensors(){
    for (const auto& zone : zones){
        zone->deactivate();
    }
}

void EmergencyCenter::activateSensorByID(int sensorID) {
    auto sensor = findSensorByID(sensorID);
    if (sensor) {
        sensor->activate();
    } else {
        throw std::runtime_error("Sensor not found with ID: " + std::to_string(sensorID));
    }
}

void EmergencyCenter::deactivateSensorByID(int sensorID) {
    auto sensor = findSensorByID(sensorID);
    if (sensor) {
        sensor->deactivate();
    } else {
        throw std::runtime_error("Sensor not found with ID: " + std::to_string(sensorID));
    }
}


void EmergencyCenter::activateSensorsInZone(int zoneID) {
    auto zone = findZoneByID(zoneID);
    if (zone) {
        zone->activate();
    } else {
        throw std::runtime_error("Zone not found with ID: " + std::to_string(zoneID));
    }
}

void EmergencyCenter::deactivateSensorsInZone(int zoneID) {
    auto zone = findZoneByID(zoneID);
    if (zone) {
        zone->deactivate();
    } else {
        throw std::runtime_error("Zone not found with ID: " + std::to_string(zoneID));
    }
}

void EmergencyCenter::testAllSensors() {
    for (const auto& zone : zones) {
        zone->test();
    }
}

void EmergencyCenter::testSensorByID(int sensorID) {
    auto sensor = findSensorByID(sensorID);
    if (sensor) {
        sensor->test();
    } else {
        throw std::runtime_error("Sensor not found with ID: " + std::to_string(sensorID));
    }
}

void EmergencyCenter::testSensorsInZone(int zoneID) {
    for (const auto& zone : zones) {
        if (zone->getID() == zoneID) {
            zone->test();
        }
    }
}

std::vector<std::shared_ptr<SensorComponent>> EmergencyCenter::getActiveSensors() {
    std::vector<std::shared_ptr<SensorComponent>> activeSensors;
    for (const auto& zone : zones) {
        for (const auto& component : zone->getAllSensorComponents()) {
            auto sensor = std::dynamic_pointer_cast<Sensor>(component);
            if (sensor && sensor->getStatus() == SensorStatus::Active) {
                activeSensors.push_back(sensor); // Add the shared_ptr to the vector
            }
        }
    }
    return activeSensors;
}

std::vector<std::shared_ptr<SensorComponent>> EmergencyCenter::getSensorsByVendor(const std::string& vendor) {
    std::vector<std::shared_ptr<SensorComponent>> vendorSensors;
    for (const auto& zone : zones) {
        auto sensors = zone->getSensorsByVendor(vendor);
        vendorSensors.insert(vendorSensors.end(), sensors.begin(), sensors.end());
    }
    return vendorSensors;
}

void EmergencyCenter::printSensorsFromVendor(const std::string& vendor) {
    auto vendorSensors = getSensorsByVendor(vendor);
    std::cout << "Sensors from Vendor: " << vendor << std::endl;
    for (const auto& sensorComponent : vendorSensors) {
        auto sensor = std::dynamic_pointer_cast<Sensor>(sensorComponent);
        if (sensor) {
            std::cout << "ID: " << sensor->getID()
            << ", Status: " << (sensor->getStatus() == SensorStatus::Active ? "Active" : "Inactive")
            << std::endl;
        }
    }
}

//private helper functions

std::shared_ptr<Sensor> EmergencyCenter::findSensorByID(int sensorID) {
    for (const auto& zone : zones) {
        for (const auto& component : zone->getAllSensorComponents()) {
            auto sensor = std::dynamic_pointer_cast<Sensor>(component);
            if (sensor && sensor->getID() == sensorID) {
                return sensor;
            }
        }
    }
    return nullptr;
}

std::shared_ptr<SensorZone> EmergencyCenter::findZoneByID(int zoneID) {
    for (const auto& zone : zones) {
        if (zone->getID() == zoneID) {
            return zone;
        }
    }
    return nullptr;
}

