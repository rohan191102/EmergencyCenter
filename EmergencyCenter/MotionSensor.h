#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "Sensor.h"
#include <string>

class MotionSensor : public Sensor {

public:

    MotionSensor(SensorZone* zone, std::string vendor, float sensitivity);

    std::string getSensorType() const override;

    void sendAlarm(int threshold);

    void test() override;

private:
    float sensitivity;
};

#endif // MOTIONSENSOR_H

