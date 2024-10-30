#include "ActionStrategy.h"
#include <iostream>

// maybe this is no need, bcs for diffrent scenarios we will have different actions for sensors, let's implement them there
void TurnOnLights::execute() {
    std::cout << "Lights are on" << std::endl;
}

void EvacuateBuilding::execute() {
    std::cout << "Please evacuate the building" << std::endl;
}

void NotifyPolice::execute() {
    std::cout << "police alerted " << std::endl;
}


SendEmail::SendEmail(const std::string& email) : emailAddr(email) {}

void SendEmail::execute() {
    std::cout << "Sending email to: " << emailAddr << std::endl;
}

// to send msg or sms
SendMessage::SendMessage(const std::string& addr) : Addr(addr) {}

void SendMessage::execute() {
    std::cout << "Sending msg to: " << Addr << std::endl;
}


void TurnOnAC::execute() {
    std::cout << "Turning on the air conditioning system" << std::endl;
}


void ActivateSprinkler::execute() {
    std::cout << "Activating sprinkler system" << std::endl;
}


void SetOffHouseAlarm::execute() {
    std::cout << "Setting off house alarm system" << std::endl;
}

void allAlarm::execute() {
    std::cout << "all alarms in all houses are activated" << std::endl;
}

