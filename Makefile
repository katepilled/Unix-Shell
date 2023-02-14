CC=gcc
CFLAGS=-g -pedantic -std=gnu17 -Wall -Werror -Wextra

.PHONY: all
all: nyush

nyush: main.o prompt.o

main.o: main.c prompt.h

prompt.o: prompt.c prompt.h

.PHONY: clean
clean:
	rm -f *.o nyush
