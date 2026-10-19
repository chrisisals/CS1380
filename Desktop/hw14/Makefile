CC = gcc
CFLAGS = -Wall -Wextra -std=c23

specials: main.o specials.o
	$(CC) $(CFLAGS) -o specials main.o specials.o

main.o: main.c specials.h
	$(CC) $(CFLAGS) -c main.c

specials.o: specials.c specials.h
	$(CC) $(CFLAGS) -c specials.c

clean:
	rm -f *.o specials
