#ifndef SENSORCOMPONENT_H
#define SENSORCOMPONENT_H

class SensorComponent {
public:
    virtual ~SensorComponent() {} // destructor
    // pure virtual functions
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void test() = 0;
    virtual int getID() const = 0;
};

#endif // SENSORCOMPONENT_H

