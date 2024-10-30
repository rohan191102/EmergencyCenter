#ifndef EMERGENCYCENTER_H
#define EMERGENCYCENTER_H

#include "SensorZone.h"
#include "Sensor.h"
#include <string>
#include <vector>
#include <memory>

class EmergencyCenter
{
public:
    EmergencyCenter(const std::string& centerName);

    //zone management
    void addZone(const std::shared_ptr<SensorZone>& zone);
    void removeZone(const std::shared_ptr<SensorZone>& zone);
    std::vector<std::shared_ptr<SensorZone> > getZones() const;
    std::weak_ptr<SensorZone> getZoneByName(const std::string& name);
    std::weak_ptr<SensorZone> getZoneByID(int zoneID);

    //sensor activation/deactivation
    void activateAllSensors();
    void deactivateAllSensors();
    void activateSensorByID(int sensorID);
    void deactivateSensorByID(int sensorID);
    void activateSensorsInZone(int zoneID);
    void deactivateSensorsInZone(int zoneID);

    //sensor testing
    void testAllSensors();
    void testSensorByID(int sensorID);
    void testSensorsInZone(int zoneID);

    //sensor queries
    std::vector<std::shared_ptr<SensorComponent>> getActiveSensors();
    std::vector<std::shared_ptr<SensorComponent>> getSensorsByVendor(const std::string& vendor);
    void printSensorsFromVendor(const std::string& vendor);

private:
    //attributes
    std::string centerName;
    std::vector<std::shared_ptr<SensorZone>> zones;

    //helper functions
    std::shared_ptr<Sensor> findSensorByID(int sensorID);
    std::shared_ptr<SensorZone> findZoneByID(int zoneID);

};

#endif // EMERGENCYCENTER_H


