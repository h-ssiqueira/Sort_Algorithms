CC = gcc
CFLAGS = -c -O3 -lm

# Directories
SRC_DIR = src/
OBJ_DIR = bin/

# Objects
SRC_FILES := $(wildcard $(SRC_DIR)**/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# Main rule
all: sort

# Rules to compile into an executable file "sort"
sort: bin ${OBJ_FILES}
	${CC} ${OBJ_FILES} -o sort

# Create the folder for binaries
bin:
	mkdir -p bin

# Generate objects
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
        ${CC} ${CFLAGS} $< -o $@

# Clear all objects
clean:
	rm -rf ${OBJ_DIR}*.o

# Clear all
rmproper: clean
	rm -rf sort

# Compile and run
cr: sort
	./sort

# Run executable
run:
	./sort