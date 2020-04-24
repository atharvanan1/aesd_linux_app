##########################################
# Author: Atharva Nandanwar
# Email : Atharva.Nandanwar@Colorado.EDU
# Makefile to build - project apps
##########################################"

# Option for Cross Compilation
ifeq ($(CC),)
	CC = $(CROSS_COMPILE)gcc
endif

ifeq ($(CFLAGS),)
	CFLAGS = -g -Wall -Werror
endif

# Targets
all: hello_world azure

hello_world: hello_world_app/hello_world.c
	@echo "Compiling with $(CC)"
	@$(CC) $(CFLAGS) $(INCLUDES) hello_world_app/hello_world.c -o hello_world $(LDFLAGS)
	@echo "Compilation finished"

azure: azure/*.c
	echo "Building azure app"
	$(MAKE) -C $(INCLUDES) azure

tmp102: tmp102/*.c
	@echo "Compiling with $(CC)"
	@$(CC) $(CFLAGS) $(INCLUDES) tmp102.c main.c -o tmp102 $(LDFLAGS)
	@echo "Compilation finished"

# Phony Target for cleaning the build and running the azure makefile
.PHONY: clean azure

clean:
	@rm -rf hello_world 
	@rm -rf azure/azure_app
	@rm -rf tmp102/tmp102
	@echo "Build cleaned"
