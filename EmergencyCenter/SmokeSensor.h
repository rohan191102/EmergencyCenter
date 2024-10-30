#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

#include "Sensor.h"

class SmokeSensor : public Sensor {
private:
    float smokeConcentration;  // Temperature value

public:
    // Constructor
    SmokeSensor(SensorZone* zone, std::string vendor, float smokeConcentration);

    // Implement getSensorType method
    std::string getSensorType() const override;

    // Additional functionality for temperature sensors
    void sendAlarm(float threshold);

    // Implement test method
    void test() override;

    // Set threshold for triggering the alarm
    void setSmokeThreshold(float threshold);
};

#endif // SMOKESENSOR_H
