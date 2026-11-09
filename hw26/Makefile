CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -g
TARGET = basic_file_ops
SRC = basic_file_ops.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: clean
