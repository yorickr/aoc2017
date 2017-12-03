
CC=gcc
CFLAGS=-pedantic -Wextra -Wall

AR=ar

SRC_DIR=./
OBJ_DIR=./

INCLUDES=-I ./include

LIBRARY=libgenetic-algo.a

SRC=$(shell find . -name "*.c")

OBJ=$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

EXECUTABLE=aoc

release: all

all: CFLAGS+=-O2
all: $(EXECUTABLE)

debug: CFLAGS+=-O0 -g
debug: $(EXECUTABLE)

%.c%.o:
	$(CC) -c -o $@ $< $(CPPFLAGS)

# Make the executable named EXECUTABLE using CC
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $(CPPFLAGS) $(OBJ) $(INCLUDES)

# Generate the static library
# TODO: Get this working.
$(LIBRARY): $(OBJ)
	$(AR) rcs $@ $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f $(EXECUTABLE)
	rm -f $(LIBRARY)
