CC=gcc
CFLAGS=-Wall -Werror -Wextra
LDFLAGS=
SOURCES=s21_string.c s21_string_test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/

all:strlen_tests strcmp_tests strcpy_tests strcat_tests

strlen_tests:$(SOURCES)
	$(CC) $(CFLAGS) -DSTRLEN_TESTS $(SOURCES) -o $(EXECUTABLE)Quest_1

strcmp_tests:$(SOURCES)
	$(CC) $(CFLAGS) -DSTRCMP_TESTS $(SOURCES) -o $(EXECUTABLE)Quest_2

strcpy_tests:$(SOURCES)
	$(CC) $(CFLAGS) -DSTRCPY_TESTS $(SOURCES) -o $(EXECUTABLE)Quest_3

strcat_tests:$(SOURCES)
	$(CC) $(CFLAGS) -DSTRCAT_TESTS $(SOURCES) -o $(EXECUTABLE)Quest_4
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o ../build/Quest_*

rebuild:clean all