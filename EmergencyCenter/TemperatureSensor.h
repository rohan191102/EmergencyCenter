#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor {
private:
    float temp;  // Temperature value

public:
    // Constructor
    TemperatureSensor(SensorZone* zone, std::string vendor, float temp);

    // Implement getSensorType method
    std::string getSensorType() const override;

    // Additional functionality for temperature sensors
    void sendAlarm(float threshold);

    // Implement test method
    void test() override;

    // Set threshold for triggering the alarm
    void setTemperatureThreshold(float threshold);
};

#endif // TEMPERATURESENSOR_H
