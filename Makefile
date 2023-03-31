CC=gcc
CFLAGS=-I.
DEPS = lib/menu.h

all: galactic-warrior

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

galactic-warrior: main.o lib/menu.o
	$(CC) $(CFLAGS) -o galactic-warrior main.o lib/menu.o

clean:
	rm -f *.o galactic-warrior

run: galactic-warrior
	./galactic-warrior
