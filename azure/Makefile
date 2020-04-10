##########################################
# Author: Atharva Nandanwar
# Email : Atharva.Nandanwar@Colorado.EDU
# Makefile to build - "azure_app"
##########################################"

# Option for Cross Compilation
ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif

ifeq ($(CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

INC=-I/usr/include/azureiot
#LIBS=-laziotsharedutil -liothub_client -liothub_client_mqtt_transport -liothub_client_mqtt_ws_transport -lpthread -liothub_client_amqp_transport -liothub_client_amqp_ws_transport -liothub_client_http_transport -lssl -lcrypto -lcurl -luuid -lm -lparson
LIBS=-liothub_client \
    -liothub_client_mqtt_transport \
    -lumqtt \
    -lprov_auth_client \
    -lhsm_security_client \
    -laziotsharedutil \
    -lparson \
    -luhttp \
    -lpthread \
    -lcurl \
    -lssl \
    -lcrypto \
    -lm \
    -luud


# Targets
all: azure_app

azure_app: azure_app.c azure_driver.c
	echo "Compiling with $(CC)"
	$(CC) $(CFLAGS) $(INCLUDES) $(INC) azure_app.c azure_driver.c -o azure_app $(LIBS) $(LDFLAGS)
	echo "Compilation finished"

# Phony Target for cleaning the build
.PHONY: clean

clean:
	rm -rf azure_app 
	echo "Build cleaned"
