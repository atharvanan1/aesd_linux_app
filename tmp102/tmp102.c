/************************************************
 * Author - Atharva Nandanwar
 * File - tmp102.c
 * Purpose - implementation for tmp102 functions
 ***********************************************/

/*********** Include Files ***********/
#include "tmp102.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <unistd.h>
#include <stdio.h>

/*********** Macro definitions ***********/
// Slave address of TMP102
#define TMP_102_ADDR    0x48
// Connects to I2C5 peripheral, address 0x40015000
#define I2C_DEVICE      "/dev/i2c-1"
// Address to Temperature Register
#define TEMP_REG        0x00
// Address to Configuration Register
#define CONFIG_REG      0x01
// Macro for checking tmp_code MSB
#define TMP_MSB         0x0800
// Resolution of temperature sensor - used for calculations
#define TMP_RES         0.0625f
// Used for shifting MSB
#define BIT_11         11

/*********** Function Prototype ***********/
/**
 * @brief TMP102_Init
 * Initializes TMP102 Sensor and sets up the pointer address to 
 * temperature address
 * @return true - if an error occurs
 * @return false - if init successful
 */
bool TMP102_Init(void)
{
    int sensor_fd;
    bool retval = false;
    bool file_open = false;

    // Get the fd for I2C Device
    if(sensor_fd = open(I2C_DEVICE, O_RDWR) < 0) {
        syslog(LOG_ERR, "File Open: %s", strerror(errno));
        retval = true;
        goto error_exit;
    }
    file_open = true;

    // Set it as slave
    if(ioctl(sensor_fd, I2C_SLAVE, TMP_102_ADDR) < 0) {
        syslog(LOG_ERR, "Error while initializing I2C Bus: %s", strerror(errno));
        retval = true;
        goto error_exit;
    }

    // Write address of temperature register
    uint8_t init_value = TEMP_REG;
    if(write(sensor_fd, &init_value, 1)){
        syslog(LOG_ERR, "Error while writing: %s", strerror(errno));
        retval = true;
        goto error_exit;
    }

    // Handle errors here
error_exit:
    if(file_open) {
        close(sensor_fd);
    }
    return retval;
}

/**
 * @brief TMP102_Read
 * gets the sensor value from TMP102
 * @return float - temperature value
 */
float TMP102_Read(void)
{
    int sensor_fd;
    float temperature = 0;
    bool file_open = false;

    // Get fd for I2C Device
    if(sensor_fd = open(I2C_DEVICE, O_RDWR) < 0) {
        syslog(LOG_ERR, "File Open: %s", strerror(errno));
    }
    file_open = true;

    // Read from sensor
    uint8_t sensor_data[2] = {0 , 0};
    if(read(sensor_fd, sensor_data, 2) != 2) {
        syslog(LOG_ERR, "Error while initializing I2C Bus: %s", strerror(errno));
    }

    // Close the file when operation over
    if(file_open) {
       close(sensor_fd);
    }
    
    // Algorithm for calculating temperature for digital data
    uint16_t tmp_code = sensor_data[1] << 4 + sensor_data[0] >> 4;
    if((tmp_code & TMP_MSB >> BIT_11)) {
        tmp_code = ~(tmp_code) & 0x0FFF;
        tmp_code += 1;
        temperature = tmp_code * TMP_RES * -1;
    }
    else {
        tmp_code = tmp_code & 0x0FFF;
        temperature = tmp_code * TMP_RES;
    }
    return temperature;
}