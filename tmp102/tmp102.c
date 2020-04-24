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
#define I2C_DEVICE      "/dev/i2c-1"
#define TEMP_REG        0x00
#define CONFIG_REG      0x01

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
        goto error_exit;
    }

error_exit:
    if(file_open) {
        close(sensor_fd);
    }
    return retval;
}

void TMP102_Read(void)
{
    int sensor_fd;
    bool retval = false;
    bool file_open = false;

    if(sensor_fd = open(I2C_DEVICE, O_RDWR) < 0) {
        syslog(LOG_ERR, "File Open: %s", strerror(errno));
        // retval = true;
    }
    // file_open = true;

    uint8_t sensor_data[2] = {0 , 0};
    if(read(sensor_fd, sensor_data, 2) != 2) {
        syslog(LOG_ERR, "Error while initializing I2C Bus: %s", strerror(errno));
        // retval = true;
    }

    printf("Sensor Data = %x, %x\n", sensor_data[1], sensor_data[0]);

    close(sensor_fd);
}
