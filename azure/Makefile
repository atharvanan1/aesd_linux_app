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

# Targets
all: azure_app

azure_app: azure_app.c azure_driver.c
	@echo "Compiling with $(CC)"
	@$(CC) $(CFLAGS) $(INCLUDES) azure_app.c azure_driver.c -o azure_app $(LDFLAGS)
	@echo "Compilation finished"

# Phony Target for cleaning the build
.PHONY: clean

clean:
	@rm -rf azure_app 
	@echo "Build cleaned"
