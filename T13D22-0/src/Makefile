CC=gcc
CFLAGS=-Wall -Werror -Wextra
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/

all:cipher

cipher:
	$(CC) $(CFLAGS) cipher.c -o $(EXECUTABLE)cipher
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm ../build/*

rebuild:clean all