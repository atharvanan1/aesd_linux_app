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
	CFLAGS = -g
endif

# Targets
all: tmp102

tmp102: main.c tmp102.c
	@echo "Compiling with $(CC)"
	@$(CC) $(CFLAGS) $(INCLUDES) main.c tmp102.c -o tmp102 $(LDFLAGS)
	@echo "Compilation finished"

# Phony Target for cleaning the build and running the azure makefile
.PHONY: clean

clean:
	@rm -rf tmp102
	@echo "Build cleaned"
