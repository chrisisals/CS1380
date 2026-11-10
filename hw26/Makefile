CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -g

TARGETS = basic_file_ops text_copy binary_records

all: $(TARGETS)

basic_file_ops: basic_file_ops.c
	$(CC) $(CFLAGS) -o $@ $^

text_copy: text_copy.c
	$(CC) $(CFLAGS) -o $@ $^

binary_records: binary_records.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS)

.PHONY: all clean
