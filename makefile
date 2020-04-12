##########################################
# Author: Atharva Nandanwar
# Email : Atharva.Nandanwar@Colorado.EDU
# Makefile to build - "writer"
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
	$(MAKE) -C azure

# Phony Target for cleaning the build
.PHONY: clean

clean:
	@rm -rf hello_world 
	rm -rf azure/azure_app
	@echo "Build cleaned"
