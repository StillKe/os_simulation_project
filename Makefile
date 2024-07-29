# Compiler and tools
CC = gcc
CFLAGS = -Wall -Iinclude

# Source files and output
SRC = src/os_simulation.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = build/os_simulation_project

# Default target
all: $(TARGET)

# Compile source files to object files
build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Clean up build artifacts
clean:
	rm -f build/*.o build/$(TARGET)