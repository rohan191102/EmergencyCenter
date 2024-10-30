TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        EmergencyCenter.cpp \
        GasSensor.cpp \
        MotionSensor.cpp \
        Sensor.cpp \
        SensorZone.cpp \
        SmokeSensor.cpp \
        TemperatureSensor.cpp \
        main.cpp \
        ActionStrategy.cpp \
        IDGen.cpp

HEADERS += \
    ActionStrategy.h \
    EmergencyCenter.h \
    GasSensor.h \
    MotionSensor.h \
    Sensor.h \
    SensorComponent.h \
    SensorStatus.h \
    SensorZone.h \
    SmokeSensor.h \
    TemperatureSensor.h \
    IDGen.h
