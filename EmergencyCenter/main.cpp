// #include <iostream>
// #include <memory>
// #include <string>
// #include "GasSensor.h"
// #include "SensorZone.h"
// #include "SmokeSensor.h"
// #include "TemperatureSensor.h"

// int main() {
// /////////////////////////// Tao's tests /////////////////////////////////////

// // Create a SensorZone object
// SensorZone zone(101, "Building A, Campus 1, Room 101");

// // Create a GasSensor object with a zone, vendor, and gas concentration
// GasSensor* gasSensor = new GasSensor(&zone, "VendorX", 50.5);

// // Add the GasSensor to the SensorZone as a component
// zone.addComponent(gasSensor);

// // Test the zone's description
// std::cout << "Zone Description: " << zone.getDescription() << std::endl;

// // Test the sensor's type
// std::cout << "Sensor Type: " << gasSensor->getSensorType() << std::endl;

// // Test if the sensor is active at a certain time
// float testHour = 9.0;
// gasSensor->setActiveHours(6.0, 18.0); // Set active hours for sensor
// if (gasSensor->isActiveAtTime(testHour)) {
//     std::cout << "Sensor is active at " << testHour << " hours." << std::endl;
// } else {
//     std::cout << "Sensor is not active at " << testHour << " hours." << std::endl;
// }

// // Test sendAlarm function with a threshold
// int threshold = 40;
// std::cout << "Testing sendAlarm with threshold " << threshold << std::endl;
// gasSensor->sendAlarm(threshold);

// // Test the test method
// gasSensor->test();

// // Clean up dynamically allocated sensor
// delete gasSensor;



// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////testing strategy////////////////////////////////

// //instantiate scenario 2
//     SensorZone testZone1(21, "John, shed");
//     SensorZone testZone2(22, "Vicky, kitchen");    // here should have a list of smoke sensors bcs for every kitchen there will be a smoke sensor
//     // SensorZone testZone3(23, "Dave, ")

// //initiate 2 sensor constructors (or objects?) ,since sensor class is abstract, we can just create a concrete sensor type.
//     // SmokeSensor* smokeSensor = new SmokeSensor(&testZone1, "IcanCU", 50);
//     // testZone1.addComponent(smokeSensor);
//     // std::cout << "Zone Description2: " << testZone2.getDescription() << std::endl;
//     // std::cout << "Sensor Type2: " << smokeSensor->getSensorType() << std::endl;
//     // GasSensor* gasSensor = new GasSensor(&testZone1, "IcanCU", 50.5);   // can I use smart pointer for this? yes, see next line
//     auto gasSensor = std::make_shared<GasSensor>(&testZone1, "IcanCU", 50.5);// avoid mem leaking by using smart pointer
//     testZone1.addComponent(gasSensor);
//     // testZone1.addCDomponent(gasSensor.get()); // here use .get() to obtain the original pointer, otherwise what will happend???
//     std::cout << "Zone Description2: " << testZone2.getDescription() << std::endl;
//     std::cout << "Sensor Type2: " << gasSensor->getSensorType() << std::endl;


//     auto smokeSensor = std::make_shared<SmokeSensor>(&testZone1, "smokingGuys", 30.1);
//     testZone1.addComponent(smokeSensor);
//     // testZone1.addComponent(smokeSensor.get()); // here use .get() to obtain the original pointer, otherwise what will happend???
//     std::cout << "Zone Description3: " << testZone2.getDescription() << std::endl;
//     std::cout << "Sensor Type3: " << smokeSensor->getSensorType() << std::endl;


//     auto tempSensor = std::make_shared<TemperatureSensor>(&testZone1, "tempingPump", 100.0);
//     testZone1.addComponent(tempSensor); // if smart ptr cannot use sensor.get(), why? bcs sensor.get() returns the original ptr, not suitable for smart s
//     // testZone1.addComponent(tempSensor.get()); // here use .get() to obtain the original pointer, otherwise what will happend???
//     std::cout << "Zone Description3: " << testZone2.getDescription() << std::endl;
//     std::cout << "Sensor Type3: " << tempSensor->getSensorType() << std::endl;

// // print current sensor
//     // std::cout << "Current gas sensor details:" << std::endl; // I think can show the enumeration here
//     std::cout << "Vendor: " << gasSensor->getVendor() << std::endl;
//     std::cout << "Vendor: " << smokeSensor->getVendor() << std::endl;

// // "addActionStrategy()" to add strategies///////
//     // first create pointers point to the actions we implemented in action.cpp
//     auto turnLights = std::make_shared<TurnOnLights>();
//     auto evacuate = std::make_shared<EvacuateBuilding>();
//     auto notify = std::make_shared<NotifyPolice>();

//     // std::shared_ptr<ActionStrategy> actionList; // create an shared_ptr, binding to gasSensor.
//     std::vector<std::shared_ptr<ActionStrategy>> actionList; // create an shared_ptr, binding to gasSensor.

//     actionList.push_back(turnLights);
//     actionList.push_back(evacuate);
//     actionList.push_back(notify);
//     for(const auto& action : actionList) {
//         gasSensor->addActionStrategy(action);
//     };

//     // // or add them one by one
//     // gasSensor->addActionStrategy(std::make_shared<TurnOnLights>());
//     // gasSensor->addActionStrategy(std::make_shared<EvacuateBuilding>());
//     // gasSensor->addActionStrategy(std::make_shared<NotifyPolice>());

//     std::vector<std::shared_ptr<ActionStrategy>> actionList2; // create an shared_ptr, binding to gasSensor.

//     // actionList2.push_back(turnLights);
//     // actionList2.push_back(evacuate);
//     // actionList2.push_back(notify);
//     // for(const auto& action : actionList2) {
//     //     smokeSensor->addActionStrategy(action);
//     // };
//     // or add them one by one
//     // smokeSensor->addActionStrategy(std::make_shared<TurnOnLights>());
//     // // smokeSensor->addActionStrategy(std::make_shared<EvacuateBuilding>());
//     // smokeSensor->addActionStrategy(std::make_shared<NotifyPolice>());

//     std::vector<std::shared_ptr<ActionStrategy>> actionList3; // for temp sensor //some hints show this we might not need this, yes im correct, bcs the shared ptr already there in the sensor class

//     tempSensor->addActionStrategy(std::make_shared<TurnOnLights>());
//     tempSensor->addActionStrategy(std::make_shared<EvacuateBuilding>());
//     // smokeSensor->addActionStrategy(std::make_shared<NotifyPolice>());



// // // test 1: directly print the actions vector in a sensor
// //     std::cout << "***************Executing all actions in actionList ************************* \n" << std::endl;
// //     for(const auto& action : actionList) {
// //         action->execute();
// //     }

// // // test 2: use trigger() to print actions
// //     std::cout << " **************************Testing actions through trigger():***************** \n" << std::endl;
// //     gasSensor->trigger();   // this will proof the actionsList is bound to gasSensor

// // // test 3: use alarm() to print actions
// //     std::cout << "************************Testing actions through sensor alarm(): *********************** \n" << std::endl;
// //     gasSensor->alarm();

// // // test 4: use send alarm
// //     std::cout << "************************Testing actions through Sendalarm(): *********************** \n" << std::endl;
// //     gasSensor->sendAlarm(30);


// // std::cout << "***************Executing all actions in actionList ************************* \n" <<"for"<<smokeSensor->getSensorType()<<"at"<<testZone2.getDescription()<< std::endl;
// // for(const auto& action : actionList2) {
// //     action->execute();
// // }

// // std::cout << " **************************Testing actions through trigger():***************** \n" << std::endl;
// // smokeSensor->trigger();   // this will proof the actionsList is bound to gasSensor

// // std::cout << "************************Testing actions through sensor alarm(): *********************** \n" << std::endl;
// // smokeSensor->alarm();

// // // test 4: use send alarm
// // std::cout << "************************Testing actions through Sendalarm(): *********************** \n" << std::endl;
// // gasSensor->sendAlarm(30);


// std::cout << "***************Executing all actions in actionList ************************* \n"<< std::endl;
// for(const auto& action : actionList3) {
//     action->execute();
// }

// std::cout << " **************************Testing actions through trigger():***************** \n" << std::endl;
// tempSensor->trigger();   // this will proof the actionsList is bound to gasSensor

// std::cout << "************************Testing actions through sensor alarm(): *********************** \n" << std::endl;
// tempSensor->alarm();

// // test 4: use send alarm
// std::cout << "************************Testing actions through Sendalarm(): *********************** \n" << std::endl;
// tempSensor->sendAlarm(80);



// ///////////////////////////testing strategy////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






// ///////////////////////////////////////////////////////////////////////////////
// //////////////////////////testing composite ///////////////////////////////////
// SensorZone testZone10(21, "John, shed");
// std::cout << "\n=== Creating Sensor Zone ===\n";
// SensorZone mainZone(1, "Building A - Main Hall");
// std::cout << "Zone Description: " << mainZone.getDescription() << "\n";

// auto gasSensor = std::make_shared<GasSensor>(&mainZone, "GasCompany", 50.5);
// auto smokeSensor = std::make_shared<SmokeSensor>(&mainZone, "SmokeCompany", 30.1);
// auto tempSensor = std::make_shared<TemperatureSensor>(&mainZone, "TempCompany", 100.0);

// // bind sensor to Zone (component)
// std::cout << "\n=== Adding Sensors to Zone ===\n";
// mainZone.addComponent(gasSensor);
// std::cout << "Added " << gasSensor->getSensorType() << " sensor from " << gasSensor->getVendor() << "\n";

// mainZone.addComponent(smokeSensor);
// std::cout << "Added " << smokeSensor->getSensorType() << " sensor from " << smokeSensor->getVendor() << "\n";

// mainZone.addComponent(tempSensor);
// std::cout << "Added " << tempSensor->getSensorType() << " sensor from " << tempSensor->getVendor() << "\n";

// // bind strategy to sensors
// std::cout << "\n=== Setting up Action Strategies ===\n";
// // here is to create actions, they are ptrs, and can be easily bound to sensors
// auto turnLights = std::make_shared<TurnOnLights>();
// auto evacuate = std::make_shared<EvacuateBuilding>();
// auto notify = std::make_shared<NotifyPolice>();

// // gas sensor actions
// gasSensor->addActionStrategy(turnLights);
// gasSensor->addActionStrategy(evacuate);
// gasSensor->addActionStrategy(notify);
// std::cout << "Added all strategies to Gas Sensor\n";

// // smoke sensor actions
// smokeSensor->addActionStrategy(turnLights);
// smokeSensor->addActionStrategy(notify);
// std::cout << "Added lights and notify strategies to Smoke Sensor\n";

// // temp sensor actions
// tempSensor->addActionStrategy(turnLights);
// tempSensor->addActionStrategy(evacuate);
// std::cout << "Added lights and evacuate strategies to Temperature Sensor\n";

// // test composite operations (active/deactive/test etc.)
// std::cout << "\n=== Testing Composite Operations ===\n";
// std::cout << "Activating all sensors in zone:\n";
// mainZone.activate();

// std::cout << "\nTesting all sensors in zone:\n";
// mainZone.test();

// // get a list of sensor
// std::cout << "\n=== Listing All Sensors ===\n";
// auto allSensors = mainZone.getAllSensors();   // why 'allsensors' never been declared, legal in c++? who says so, click it u know
// std::cout << "Total sensors in zone: " << allSensors.size() << "\n";
// for (const auto& sensor : allSensors) {
//     std::cout << "Found " << sensor->getSensorType()
//     << " sensor from " << sensor->getVendor() << "\n";
// }

// // test alarms
// std::cout << "\n=== Testing Sensor Alarms and Strategies ===\n";

// std::cout << "\nTesting Gas Sensor Alarm:\n";
// gasSensor->sendAlarm(60.0);

// std::cout << "\nTesting Smoke Sensor Alarm:\n";
// smokeSensor->sendAlarm(40.0);

// std::cout << "\nTesting Temperature Sensor Alarm:\n";
// tempSensor->sendAlarm(120.0);

// // test of removing a sensor (remove a component)
// std::cout << "\n=== Testing Sensor Removal ===\n";
// std::cout << "Removing smoke sensor...\n";
// mainZone.removeComponent(smokeSensor);

// allSensors = mainZone.getAllSensors();
// std::cout << "Remaining sensors in zone: " << allSensors.size() << "\n";
// for (const auto& sensor : allSensors) {
//     std::cout << "Remaining sensor: " << sensor->getSensorType()
//     << " from " << sensor->getVendor() << "\n";
// }

// // deactive all sensors
// std::cout << "\n=== Final Deactivation ===\n";
// mainZone.deactivate();

// noted: all test starts after calling "activate()" and dont forget "deactivate()" at the end


// /////////////////////////testing composite//////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////

// void testIDGen(){
//     auto testZone = std::make_shared<SensorZone>(1, "testZone");

//     auto sensor1 = std::make_shared<SmokeSensor>(testZone.get(), "xxx", 100);
//     auto sensor2 = std::make_shared<GasSensor>(testZone.get(), "xxxx", 100);
//     auto sensor3 = std::make_shared<MotionSensor>(testZone.get(), "xx", 100);
//     testZone->addComponent(sensor1);
//     testZone->addComponent(sensor2);
//     testZone->addComponent(sensor3);
//     std::cout << "ID1: " << sensor1->getID() << std::endl;
//     std::cout << "ID2: " << sensor2->getID() << std::endl;
//     std::cout << "ID3: " << sensor3->getID() << std::endl;

// }

// void sendEmailTest() {
//     SensorZone testZone(1, "Test Zone");
//     auto smokeSensor = std::make_shared<SmokeSensor>(&testZone, "xxxx", 30.0);
//     auto emailAction = std::make_shared<SendEmail>("test@xx.com");
//     smokeSensor->addActionStrategy(emailAction);

//     smokeSensor->activate();
//     smokeSensor->trigger();

// }


// /////////////////////////////////////////SCENARIO 1//////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "GasSensor.h"
#include "SmokeSensor.h"
#include "MotionSensor.h"
#include "SensorZone.h"
#include "EmergencyCenter.h"

int main() {

    // Instantiate Emergency Center
    EmergencyCenter center("Emergency Center");

    // For creating the zones
    SensorZone mainZone(1, "Group T Building");
    SensorZone chemistryZone(2, "Group T Building, Module 5, Room 5.01 - Chemistry Lab");
    SensorZone electronicsZone1(3, "Group T Building, Module 10, Room 10.01 - Electronics Lab");
    SensorZone electronicsZone2(4, "Group T Building, Module 10, Room 10.02 - Electronics Lab");
    SensorZone almaKitchenZone(5, "Group T Building, Module 1, Room 1.03 - Alma Kitchen");
    SensorZone Module10(6, "Group T Building Module 10");

    // Creating the sensors here
    auto smokeSensorChem = std::make_shared<SmokeSensor>(&chemistryZone, "Sensor Solution", 30.1);
    auto gasSensorChem = std::make_shared<GasSensor>(&chemistryZone, "GasSense", 50.5);
    auto smokeSensorElec = std::make_shared<SmokeSensor>(&electronicsZone1, "Sensor Solution", 25.0);
    auto motionSensorElec1 = std::make_shared<MotionSensor>(&electronicsZone1, "GotYou", true);
    auto motionSensorElec2 = std::make_shared<MotionSensor>(&electronicsZone2, "GotYou", true);
    auto smokeSensorKitchen = std::make_shared<SmokeSensor>(&almaKitchenZone, "KitchenSafe", 35.0);
    auto gasSensorKitchen = std::make_shared<GasSensor>(&almaKitchenZone, "GasSense", 45.0);
    auto motionSensorKitchen = std::make_shared<MotionSensor>(&almaKitchenZone, "BigBrother Is Watching You", true);
    gasSensorChem->addActionStrategy(std::make_shared<SendEmail>("lore.hennebel@kuleuven.be"));
    smokeSensorElec->addActionStrategy(std::make_shared<SendMessage>(" Gert Vanloock"));
    smokeSensorKitchen->addActionStrategy(std::make_shared<SendMessage>(" Alarm dispatch"));
    motionSensorKitchen->addActionStrategy(std::make_shared<NotifyPolice>());



    // Adding each sensor to a zone
    chemistryZone.addComponent(smokeSensorChem);
    chemistryZone.addComponent(gasSensorChem);

    electronicsZone1.addComponent(smokeSensorElec);
    electronicsZone1.addComponent(motionSensorElec1);

    electronicsZone2.addComponent(motionSensorElec2);

    almaKitchenZone.addComponent(smokeSensorKitchen);
    almaKitchenZone.addComponent(gasSensorKitchen);
    almaKitchenZone.addComponent(motionSensorKitchen);

    // adding all zome to main zone (head zone)(contains everything)
    mainZone.addComponent(std::make_shared<SensorZone>(chemistryZone));
    mainZone.addComponent(std::make_shared<SensorZone>(Module10));
    mainZone.addComponent(std::make_shared<SensorZone>(electronicsZone1));
    mainZone.addComponent(std::make_shared<SensorZone>(electronicsZone2));
    mainZone.addComponent(std::make_shared<SensorZone>(almaKitchenZone));
    Module10.addComponent(std::make_shared<SensorZone>(electronicsZone1));
    Module10.addComponent(std::make_shared<SensorZone>(electronicsZone2));

    // adding zones to the center

    center.addZone(std::make_shared<SensorZone>(chemistryZone));
    center.addZone(std::make_shared<SensorZone>(Module10));
    center.addZone(std::make_shared<SensorZone>(almaKitchenZone));
    // Setting Active hours
    motionSensorElec1->setActiveHours(22.0, 7.0);
    motionSensorElec2->setActiveHours(22.0, 7.0);
    motionSensorKitchen->setActiveHours(0.0, 24.0);

    std::cout << "\n Activating and Testing Smoke Sensor in Lab Chemistry  \n";
    ++(*smokeSensorChem); // directly modifies the object and returns it (prefix)
    smokeSensorChem->test();

    std::cout << "\n Activating and Testing All Sensors in Lab Chemistry  \n";
    chemistryZone.activate();
    chemistryZone.test();

    std::cout << "\n Testing All Sensors in Group T Building \n";
    center.testSensorsInZone(mainZone.getID());

    ++mainZone;  // Automatically activates all sensors in the building (it should normally)

    std::cout << "\n Testing the Whole Building \n";
    center.testAllSensors();

    std::cout << "\n Testing Module 10 \n";
    // Module10.test();
    center.testSensorsInZone(Module10.getID());

    std::cout << "\n Overview of All Sensors Ordered by Vendor \n";
    std::vector<std::string> vendors = {"Sensor Solution", "GasSense", "GotYou", "KitchenSafe", "BigBrother Is Watching You"};
    for (const auto& vendor : vendors) {
        std::cout << "\nSensors from " << vendor << ":\n";
        for (const auto& sensor : mainZone.getSensorsByVendor(vendor)) {
            std::cout << "Found " << sensor->getSensorType() << " in " << sensor->getZone()->getDescription() << "\n";
        }
    }

    return 0;
}

// /////////////////////SCENARIO 3/////////////////////////////////////////////////////////

// #include <iostream>
// #include <memory>
// #include <string>
// #include <vector>
// #include "GasSensor.h"
// #include "SmokeSensor.h"
// #include "MotionSensor.h"
// #include "SensorZone.h"

// int main() {
//     // Creating the zones
//     SensorZone mainZone(1, "Twix Galaxy");
//     SensorZone planetXZone(2, "Planet X AE A-12");
//     SensorZone volcanoRedstoneZone(3, "Planet X AE A-12, Redstone Volcano");
//     SensorZone volcanoOrangestoneZone(4, "Planet X AE A-12, Orangestone Volcano");
//     SensorZone lv426Zone(5, "Planet LV-426");
//     SensorZone moonUnitZone(6, "LV-426, Moon Unit");
//     SensorZone dweezilZone(7, "LV-426, Dweezil");

//     // Creating the sensors
//     auto motionSensorTwix = std::make_shared<MotionSensor>(&mainZone, "Disney", true);
//     auto gasSensorSulphur = std::make_shared<GasSensor>(&planetXZone, "Disney", 1000000000);
//     auto smokeSensorRedstone = std::make_shared<SmokeSensor>(&volcanoRedstoneZone, "Disney", 200);
//     auto smokeSensorOrangestone = std::make_shared<SmokeSensor>(&volcanoOrangestoneZone, "Disney", 200);
//     auto motionSensorLV426 = std::make_shared<MotionSensor>(&lv426Zone, "Disney", true);
//     auto gasSensorOxygen = std::make_shared<GasSensor>(&lv426Zone, "Disney", 1200000000);
//     auto smokeSensorMoonUnit = std::make_shared<SmokeSensor>(&moonUnitZone, "Disney", 150);
//     auto smokeSensorDweezil = std::make_shared<SmokeSensor>(&dweezilZone, "Disney", 150);
//     auto motionSensorMoonUnit = std::make_shared<MotionSensor>(&moonUnitZone, "Disney", true);
//     auto motionSensorDweezil = std::make_shared<MotionSensor>(&dweezilZone, "Disney", true);

//     // Adding each sensor to a zone
//     mainZone.addComponent(motionSensorTwix);
//     planetXZone.addComponent(gasSensorSulphur);
//     volcanoRedstoneZone.addComponent(smokeSensorRedstone);
//     volcanoOrangestoneZone.addComponent(smokeSensorOrangestone);
//     lv426Zone.addComponent(gasSensorOxygen);
//     lv426Zone.addComponent(motionSensorLV426);
//     moonUnitZone.addComponent(smokeSensorMoonUnit);
//     moonUnitZone.addComponent(motionSensorMoonUnit);
//     dweezilZone.addComponent(smokeSensorDweezil);
//     dweezilZone.addComponent(motionSensorDweezil);

//     // Adding subzones to main zones
//     mainZone.addComponent(std::make_shared<SensorZone>(planetXZone));
//     mainZone.addComponent(std::make_shared<SensorZone>(volcanoRedstoneZone));
//     mainZone.addComponent(std::make_shared<SensorZone>(volcanoOrangestoneZone));
//     mainZone.addComponent(std::make_shared<SensorZone>(lv426Zone));
//     mainZone.addComponent(std::make_shared<SensorZone>(moonUnitZone));
//     mainZone.addComponent(std::make_shared<SensorZone>(dweezilZone));

//     planetXZone.addComponent(std::make_shared<SensorZone>(volcanoRedstoneZone));
//     planetXZone.addComponent(std::make_shared<SensorZone>(volcanoOrangestoneZone));
//     lv426Zone.addComponent(std::make_shared<SensorZone>(moonUnitZone));
//     lv426Zone.addComponent(std::make_shared<SensorZone>(dweezilZone));

//     // Setting Active Hours for Motion Sensors
//     motionSensorMoonUnit->setActiveHours(20.0, 8.0);
//     motionSensorDweezil->setActiveHours(20.0, 8.0);

//     mainZone.deactivate();
//     std::cout << "\n Activating and Testing All Atmospheric Sensors \n";
//     auto atmosphericSensors = mainZone.getSensorsByType("GasSensor");
//     for (const auto& sensor : atmosphericSensors) {
//         sensor->activate();
//         sensor->test();
//     }

//     std::cout << "\n Activating and Testing All Sensors on Planet XAEA-12 \n";
//     planetXZone.activate();
//     planetXZone.test();

//     std::cout << "\n Deactivating All Sensors on LV-426 and test\n";
//     lv426Zone.deactivate();
//     lv426Zone.test();

//     std::cout << "\n Reactivating LV-426 and Testing \n";
//     lv426Zone.activate();
//     lv426Zone.test();

//     std::cout << "Testing Moon Unit:\n";
//     moonUnitZone.test();
//     std::cout << "Testing Dweezil:\n";
//     dweezilZone.test();
//     // REMAINING IS ORDER BY LOCATION AND ACTION STRATEGIES

//     return 0;
// }



