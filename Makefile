CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: program

program: main.c
	$(CC) $(CFLAGS) main.c -o program

clean:
	rm -f program