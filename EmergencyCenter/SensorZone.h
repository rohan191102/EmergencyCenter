#ifndef SENSORZONE_H
#define SENSORZONE_H

#include <memory>
#include <vector>
#include <string>
#include "SensorComponent.h"

class Sensor;  // Forward declaration needed for getAllSensors() return type

class SensorZone : public SensorComponent {
public:
    // Constructor
    SensorZone(int id, const std::string& description);  // use const reference to transfer string

    // from interface
    void activate() override;
    void deactivate() override;
    void test() override;
    int getID() const override;

    // component management methods, a component can contain multiple sensors
    void addComponent(const std::shared_ptr<SensorComponent>& component); // why ref works??
    void removeComponent(const std::shared_ptr<SensorComponent>& component);
    std::vector<std::shared_ptr<SensorComponent>> getAllSensorComponents() const;
    std::vector<std::shared_ptr<Sensor>> getAllSensors() const;    std::vector<std::shared_ptr<Sensor>> getSensorsByType(const std::string& sensorType) const;
    std::vector<std::shared_ptr<Sensor>> getSensorsByVendor(const std::string& vendor) const;
    std::vector<std::shared_ptr<Sensor>> getSensorsActiveAtTime(float time) const;
    std::vector<std::shared_ptr<Sensor>> getSensorsByZone(const SensorZone& zone) const;
    std::shared_ptr<SensorZone> findZoneByName(const std::string& description) const;
    SensorZone& operator++(); //operator overloading
    std::string getDescription() const;
    void testZoneByID(int zoneID);

    std::vector<std::shared_ptr<Sensor>> getAllSensorsSortedByID() const;

private:
    int sensorZoneID;
    std::string zoneDescription;
    std::vector<std::shared_ptr<SensorComponent>> components;
};

#endif  // SENSORZONE_H
