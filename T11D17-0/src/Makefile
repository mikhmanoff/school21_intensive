CC=gcc
CFLAGS=-Wall -Werror -Wextra
LDFLAGS=
SOURCES=dmanager_module.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/

door_struct:$(SOURCES)
	$(CC) $(CFLAGS) -DDOOR_STRUCT $(SOURCES) -o $(EXECUTABLE)Quest_1

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm ../build/Quest_*

rebuild:clean all