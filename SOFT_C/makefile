CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lwiringPi
SOURCES=main.c init_gpio.c update.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=SOFT

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm *.o SOFT
