QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = iot_sensor_gui
TEMPLATE = app

HEADERS += \
    mainwindow.h \
    tmp102.h \
    tempSensor.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tmp102.c \
    tempSensor.cpp \
