CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURCES=main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_libs/data_sort.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../../build/Quest_3
STAT_LIB_DATA=../data_module/data_process.o main_executable_module.o ../data_libs/data_io.o 

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

build_with_static: main_executable_module.o ../data_module/data_process.o ../data_libs/data_io.o ../yet_another_decision_module/decision.o ../data_libs/data_stat.o ../data_libs/data_sort.o
	gcc main_executable_module.o ../data_module/data_process.o ../data_libs/data_io.o data_stat.a ../data_libs/data_stat.o ../yet_another_decision_module/decision.o ../data_libs/data_sort.o -o ../../build/Quest_5

data_stat.a: 
	ar crs data_stat.a ../data_libs/data_stat.o

build_with_dynamic: main_executable_module.o ../data_module/data_process.o ../data_libs/data_io.o ../yet_another_decision_module/decision.o ../data_libs/data_stat.o ../data_libs/data_sort.o
	gcc -L. ../../build/data_process.so main_executable_module.o ../data_module/data_process.o ../data_libs/data_io.o ../data_libs/data_stat.o ../yet_another_decision_module/decision.o ../data_libs/data_sort.o -o ../../build/Quest_6

data_process.so: ../data_module/data_process.o ../data_libs/data_stat.o
	gcc -shared ../data_module/data_process.o ../data_libs/data_stat.o -o ../../build/data_process.so 

clean:
	rm ../data_libs/*.o ../data_libs/*.o ../data_module/*.o ../yet_another_decision_module/*.o *.o *.a ../../build/Quest_* *.a ../../build/*.so

rebuild:clean all