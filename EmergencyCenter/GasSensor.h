#ifndef GASSENSOR_H
#define GASSENSOR_H

#include "Sensor.h"
#include <string>

class GasSensor : public Sensor {
private:
    float gasConcentration;  // The concentration of gas detected by the sensor

public:
    // Constructor
    GasSensor(SensorZone* zone, std::string vendor, float gasConcentration);

    // Override the getSensorType method from the base class
    std::string getSensorType() const override;

    // Function to send an alarm if the gas concentration exceeds a threshold
    void sendAlarm(float threshold);

    // Test method to check if the sensor is working properly
    void test() override;
};

#endif // GASSENSOR_H
