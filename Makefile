MAKEFLAGS += -j4

# Compiler and flags
CC = gcc
CFLAGS = -c -O3 -lm -march=native -mtune=native

# Directories
SRC_DIR = src/
OBJ_DIR = bin/

# Files
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# Main rule
all: sort

# Rule to compile into an executable file "sort"
sort: bin ${OBJ_FILES}
	${CC} ${OBJ_FILES} -o sort

# Create the directories for binaries
bin:
	mkdir -p bin $(OBJ_DIR)esotericFunMiscellaneous $(OBJ_DIR)exchange $(OBJ_DIR)hybrids $(OBJ_DIR)insertion $(OBJ_DIR)merge $(OBJ_DIR)networksConcurrent $(OBJ_DIR)noncomparisonDistribution $(OBJ_DIR)selection $(OBJ_DIR)utils

# Generate objects
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	${CC} ${CFLAGS} $< -o $@

# Clear all objects
clean:
	find bin -name '*.o' -delete

# Clear all
rmproper: clean
	rm -rf sort

# Compile and run
cr: sort
	./sort

# Run executable
run:
	./sort