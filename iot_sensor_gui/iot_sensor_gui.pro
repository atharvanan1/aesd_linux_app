QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = iot_sensor_gui
TEMPLATE = app

HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp
