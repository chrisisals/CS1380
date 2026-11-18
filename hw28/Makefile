CC = clang
CFLAGS = -std=c23 -Wall -Wextra -Werror -pedantic

all: secure

secure: main.c secure.c secure.h
	$(CC) $(CFLAGS) main.c secure.c -o secure

test_secure: test_secure.c secure.c secure.h
	$(CC) $(CFLAGS) test_secure.c secure.c -o test_secure

test: test_secure
	./test_secure

clean:
	rm -f secure test_secure ownership *.o

.PHONY: all test clean


