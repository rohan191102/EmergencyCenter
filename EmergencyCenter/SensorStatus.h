#ifndef SENSORSTATUS_H
#define SENSORSTATUS_H

// Enum class definition
enum class SensorStatus {
    Inactive,  // Sensor is not active
    Active,    // Sensor is active
    Testing,   // Sensor is being tested
    Triggered  // Sensor has been triggered (e.g., alarm)
};

#endif // SENSORSTATUS_H

