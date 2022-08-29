CC=gcc
CFLAGS=-Wall -Werror -Wextra
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/

all:state_sort

state_sort:
	$(CC) $(CFLAGS) state_sort.c -o $(EXECUTABLE)state_sort
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm ../build/*

rebuild:clean all
