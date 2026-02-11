# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = recitation

# Source files
SRCS = Recitation.c bitOpr.c

# Object files
OBJS = Recitation.o bitOpr.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile Recitation.c
Recitation.o: Recitation.c bitOpr.h
	$(CC) $(CFLAGS) -c Recitation.c

# Compile bitOpr.c
bitOpr.o: bitOpr.c bitOpr.h
	$(CC) $(CFLAGS) -c bitOpr.c

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
