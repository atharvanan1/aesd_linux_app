#include "tmp102.h"
#include <stdio.h>
#include <syslog.h>

int main (void) {
    openlog("TMP102", LOG_ODELAY | LOG_PERROR, LOG_USER);
    syslog(LOG_DEBUG, "Log Opened");
    TMP102_Init();
    printf("%f\n", TMP102_Read());
    closelog();
    return 0;
}