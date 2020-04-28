/**
 * azure_driver.h
 * 
 * This file contains the API for the azure driver. The functions here allow
 * you to send data to the azure cloud
 */

#ifndef AZURE_DRIVER_H__
#define AZURE_DRIVER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool azure_init(void);

void azure_deinit(void);

bool azure_send_measurement(char* name, float data);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* AZURE_DRIVER_H__ */