/************************************************
 * Author - Atharva Nandanwar
 * File - tmp102.c
 * Purpose - implementation for tmp102 functions
 ***********************************************/
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

#define TMP_102_ADDR    0x48
#define I2C_DEVICE      "/dev/i2c-1"        // Connects to I2C5 peripheral
#define TEMP_REG        0x00
#define CONFIG_REG      0x01

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

    if(sensor_fd = open(I2C_DEVICE, O_RDWR) < 0) {
        syslog(LOG_ERR, "File Open: %s", strerror(errno));
        retval = true;
        goto error_exit;
    }
    file_open = true;

    if(ioctl(sensor_fd, I2C_SLAVE, TMP_102_ADDR) < 0) {
        syslog(LOG_ERR, "Error while initializing I2C Bus: %s", strerror(errno));
        retval = true;
        goto error_exit;
    }

    uint8_t init_value = TEMP_REG;
    if(write(sensor_fd, &init_value, 1)){
        syslog(LOG_ERR, "Error while writing: %s", strerror(errno));
        retval = true;
        goto error_exit;
    }

error_exit:
    if(file_open) {
        close(sensor_fd);
    }
    return retval;
}

float TMP102_Read(void)
{
    int sensor_fd;
    float temperature = 0;
    bool file_open = false;

    if(sensor_fd = open(I2C_DEVICE, O_RDWR) < 0) {
        syslog(LOG_ERR, "File Open: %s", strerror(errno));
    }
    file_open = true;

    uint8_t sensor_data[2] = {0 , 0};
    if(read(sensor_fd, sensor_data, 2) != 2) {
        syslog(LOG_ERR, "Error while initializing I2C Bus: %s", strerror(errno));
    }

    if(file_open) {
       close(sensor_fd);
    }

    temperature = sensor_data[1] << 8 + sensor_data[0];
    return temperature;
}
