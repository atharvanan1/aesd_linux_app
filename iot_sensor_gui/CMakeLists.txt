# help with this file from https://doc.qt.io/qt-5/cmake-get-started.html#build-a-gui-executable

cmake_minimum_required(VERSION 3.1.0)
project(iot_sensor_gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set ( SOURCES
 main.cpp
 mainwindow.cpp
 tempSensor.cpp
 tmp102.c
)

set ( QT_LIBRARIES
 Qt5::Core
 Qt5::Widgets
)

set (CMAKE_PREFIX_PATH /home/bryan/Qt5.14.2/5.14.2/gcc_64/lib/cmake/Qt5/)

find_package(Qt5 COMPONENTS Core REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)


# compile
add_executable(iot_sensor_gui ${SOURCES})

# build it (link libraries)
target_link_libraries(iot_sensor_gui ${QT_LIBRARIES})
