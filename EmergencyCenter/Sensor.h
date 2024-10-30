#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include <memory>
#include "ActionStrategy.h"
#include "SensorZone.h"
#include "SensorComponent.h"

enum class SensorStatus { Inactive, Active, Testing, Triggered };

class SensorZone;

class Sensor : public SensorComponent {
public:
    Sensor(SensorZone* zone, std::string vendor);

    int getID() const override;

    std::string getVendor() const;

    virtual std::string getSensorType() const = 0;
    virtual void test() override = 0;

    void setActiveHours(float startHour, float endHour);
    float getStartHour() const;
    float getEndHour() const;

    void activate() override;
    void deactivate() override;

    SensorZone* getZone() const;

    bool isActiveAtTime(float currentHour) const;

    void addActionStrategy(std::shared_ptr<ActionStrategy> strategy);
    void trigger();
    void alarm();

    Sensor& operator++();
    Sensor& operator--();
    void setStatus(SensorStatus newStatus);
    SensorStatus getStatus() const;

    friend std::ostream& operator<<(std::ostream& os, const Sensor& sensor);// << operator overloading

private:
    int sensorId;
    SensorZone* zone;
    std::string vendor;
    SensorStatus status;
    std::vector<std::shared_ptr<ActionStrategy>> actionStrategies;
    float startHour;
    float endHour;
};



#endif // SENSOR_H
