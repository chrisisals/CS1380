CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -g
TARGET = basic_recursion
SRC = basic_recursion.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: clean
