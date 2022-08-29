#ifndef SRC_STATE_SORT_H_
#define SRC_STATE_SORT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct my_struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} my_struct;

// Function of reading a record of a given type from a file by its serial number.
my_struct read_record_from_file(FILE *pfile, int index);

// Function of writing a record of the specified type to the file at the specified serial number.
void write_record_in_file(FILE *pfile, const my_struct *record_to_write, int index);

// Function of mutual transfer of two records in the file by their indexes.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);

// Function to get file size in bytes.
int get_file_size_in_bytes(FILE *pfile);

// Function to get count of records in file
int get_records_count_in_file(FILE *pfile);


#endif  // SRC_STATE_SORT_H_
