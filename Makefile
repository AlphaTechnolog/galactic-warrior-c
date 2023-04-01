CC=gcc
CFLAGS=-I.
DEPS = lib/menu.h lib/banner.h lib/termutils.h game/game.h game/board.h
OBJECT_FILES = main.o ${DEPS:.h=.o}
BINARY=galactic-warrior

all: galactic-warrior

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINARY): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECT_FILES)

clean:
	rm -f *.o */*.o $(BINARY)

run: $(BINARY)
	./$(BINARY)
