# Makefile improved by Basile Starynkevitch

CC= gcc
CFLAGS= -Wall -g
LDLIBS= -lm
SOURCES= cards.c war.c deck.c
# or perhaps SOURCES= $(wildcard *.c)

OBJECTS= $(patsubst %.c,%.o,$(SOURCES))

.PHONY: all clean

all: war

war: $(OBJECTS)

$(OBJECTS): cards.h deck.h

clean:
	$(RM) $(OBJECTS) war
