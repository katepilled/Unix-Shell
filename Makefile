CC=gcc
CFLAGS=-g -pedantic -std=gnu17 -Wall -Werror -Wextra

.PHONY: all
all: nyush

nyush: nyush.o prompt.o locating.o builtIn.o

nyush.o: nyush.c prompt.h locating.h builtIn.h

prompt.o: prompt.c prompt.h 

locating.o: locating.c locating.h

builtIn.o: builtIn.c builtIn.h


.PHONY: clean
clean:
	rm -f *.o nyush
