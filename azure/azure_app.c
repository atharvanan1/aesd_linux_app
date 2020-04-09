#include "azure_driver.h"

int main()
{
    bool error = false;

    error = azure_init();

    if (!error)
    {
        error = azure_send_measurement("temp", 20.3);
    }

    azure_deinit();

    return 0;
}