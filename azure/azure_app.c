#include "azure_driver.h"
#include <unistd.h>

int main()
{
    bool error = false;

    error = azure_init();

    if (!error)
    {
        error = azure_send_measurement("temp", 20.3);
    }

    // sleep for a few seconds to wait for a response from the cloud
    sleep(3);

    azure_deinit();

    return 0;
}
