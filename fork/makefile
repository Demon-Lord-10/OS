# Compiler to use
CC = gcc

# Compiler flags
# -Wall: Enable all common warnings (good for catching errors)
# -g:    Add debugging information (useful for gdb)
CFLAGS = -Wall -g

# The name of the final executable file
TARGET = using_fork

# The source file(s)
SRC = using_fork.c

# Default rule: running "make" will run this
all: $(TARGET)

# Rule to compile the program
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up files: running "make clean" deletes the executable
clean:
	rm -f $(TARGET)

run:
	./using_fork

