#ifndef ACTIONSTRATEGY_H
#define ACTIONSTRATEGY_H

#include <string>
// #include <memory>
#include "SensorZone.h"
// #include <iostream>


// interface
class ActionStrategy {
public:
    virtual void execute() = 0;  // pure virtual
    virtual ~ActionStrategy() = default; //destructor, should also be virtual
};

#endif // ACTIONSTRATEGY_H


// maybe no need the classes below, bcs for diffrent scenarios we will have different actions for sensors, let's implement them there

// some implementation of virtual execute(), addStrategy() in Sensor.cpp should add from here
class TurnOnLights : public ActionStrategy {  // 'implementation', similar to inheritance
public:
    void execute() override;
};

class EvacuateBuilding : public ActionStrategy {
public:
    void execute() override;
};

class NotifyPolice : public ActionStrategy {
public:
    void execute() override;
};

class SendEmail : public ActionStrategy {
private:
    std::string emailAddr;
public:
    SendEmail(const std::string& email);
    void execute() override;
};

// to send msg or sms
class SendMessage : public ActionStrategy {
private:
    std::string Addr;
public:
    SendMessage(const std::string& addr);
    void execute() override;
};

class TurnOnAC : public ActionStrategy {
public:
    void execute() override;
};

class ActivateSprinkler : public ActionStrategy {
public:
    void execute() override;
};

class SetOffHouseAlarm : public ActionStrategy {
public:
    void execute() override;
};

class allAlarm : public ActionStrategy {
public:
    void execute() override;
};


