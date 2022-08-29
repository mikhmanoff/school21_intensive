CC=gcc
CFLAGS=-Wall -Werror -Wextra
LDFLAGS=
SOURCES=print_module.c main_module_entry_point.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/

print_module:$(SOURCES)
	$(CC) $(CFLAGS) -DPRINT_MODULE $(SOURCES) -o $(EXECUTABLE)Quest_1

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm ../build/Quest_*

rebuild:clean all