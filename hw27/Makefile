CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -pthread -g

all: threads main

threads: threads.c
	$(CC) $(CFLAGS) threads.c -o threads

main: main.c
	$(CC) $(CFLAGS) main.c -o main

test: all
	./threads
	./main

clean:
	rm -f threads main

.PHONY: all test clean

