# Compiler's name
CC = gcc

# Compiler options
CFLAGS = -Wall -g

# Show the extention files in a directory
#SOURCES := $(wildcard *.c)

# Create a list of object files
#OBJECTS = $(SOURCES:.c=.o)

# Name of main executable program
#EXEC = sort

# Atribute the main object to a variable
#all: $(EXEC)

# Atribute all objects to the main executable object
#$(EXEC): $(OBJECTS)
#	$(CC) -o $@ $^

# Compile every .c to an object
#%.o: %.c
#	$(CC) -c $(CFLAGS) $^

# Clean all .o extentions
#clean:
#	rm -rf *.o

# Clean the main object program
#rmproper: clean
#	em -rf $(EXEC)


VPATH=./Esoteric\&Fun\&Miscellaneous/:./Exchange/:./Hybrids/:./Insertion/:./Merge/:./Networks\&Concurrent/:./Non-Comparison\&Distribution/:./Selection/

#EFM=$/Esoteric\&Fun\&Miscellaneous/()

SRC=$(wildcard *.c)

OBJ=$(Esoteric\&Fun\&Miscellaneous/SRC:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

EXEC=sort

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f *.o
	rm -f $(EXEC)

# Execution of the program
run: $(EXEC)
	./$(EXEC)

#https://www.quora.com/How-do-I-write-a-makefile-in-C++-to-include-files-from-different-directories