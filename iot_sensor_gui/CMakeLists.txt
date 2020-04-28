# help with this file from https://doc.qt.io/qt-5/cmake-get-started.html#build-a-gui-executable

Option(edison "set edison to ON to build the DM edison sample" OFF)

cmake_minimum_required(VERSION 3.1.0)
project(iot_sensor_gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

LIST(GET CMAKE_FIND_ROOT_PATH 0 SYSROOT_PATH)

set(AZUREIOT_INC_FOLDER ".")

include_directories(${AZUREIOT_INC_FOLDER})
include_directories(${SYSROOT_PATH}/usr/include/azureiot)

set ( SOURCES
 main.cpp
 mainwindow.cpp
 tempSensor.cpp
 tmp102.c
 azure_app.c
 azure_driver.c
)

set ( QT_LIBRARIES
 Qt5::Core
 Qt5::Widgets
)

set ( AZURE_LIBRARIES
 iothub_client
 iothub_client_mqtt_transport
 serializer
 aziotsharedutil
 umqtt
 pthread
 curl
 m
 uamqp
 uhttp
 prov_auth_client
 hsm_security_client
 parson
 ssl
 crypto
 uuid
)

find_package(Qt5 COMPONENTS Core REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)


# compile
add_executable(iot_sensor_gui ${SOURCES})

# build it (link libraries)
target_link_libraries(iot_sensor_gui ${QT_LIBRARIES} ${AZURE_LIBRARIES})
