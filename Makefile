# Makefile
CC := gcc
CLFAGS = -Wall -Werror -Wextra -std=c99
LDLIBS = -lm
LDFLAGS = 

# Source files
BRUTE_FORCE_OBJECTS = ./main_brute_force.o ./solvers/solver_brute_force/solver_brute_force.o
BASIC_OBJECTS = ./main_basic.o ./solvers/solver_basic/solver_basic.o
SOURCE := $(shell find . -type f -name "*.c" ! -path "./tests/*" ! -path "*main*" ! -path "*solvers/solver_b*")
OBJECTS = $(SOURCE:%.c=%.o)
# Test files	
SOURCE_TEST = $(shell find tests -name "*.c")
TEST_OBJECTS = $(SOURCE_TEST:%.c=%.o)

RELEASE := 0
ifneq ($(RELEASE), 0)
        CFLAGS += -O3 
else
        CFLAGS += -g -O0
endif


all: solver_basic solver_brute_force test

test : $(OBJECTS) $(TEST_OBJECTS)
	$(CC) -o build/test $(OBJECTS) $(TEST_OBJECTS) -lasan $(LDLIBS) -lcriterion

solver_basic: $(OBJECTS) $(BASIC_OBJECTS)
	$(CC) -o build/solver_basic $(BASIC_OBJECTS) $(OBJECTS) -lasan $(LDLIBS)

solver_brute_force: $(OBJECTS) $(BRUTE_FORCE_OBJECTS)
	$(CC) -o build/solver_brute_force $(BRUTE_FORCE_OBJECTS) $(OBJECTS) -lasan $(LDLIBS)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(TEST_OBJECTS)
	rm -rf $(BRUTE_FORCE_OBJECTS)
	rm -rf $(BASIC_OBJECTS)
	rm -rf build/*

.PHONY: all clean test solver_basic solver_brute_force


# END
