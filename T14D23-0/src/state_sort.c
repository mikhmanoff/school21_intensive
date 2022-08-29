#include "state_sort.h"

int compare(my_struct elem_1, my_struct elem_2) {
  int result = 0;

  if (elem_1.year > elem_2.year) {
    result = 1;
  } else if (elem_1.year < elem_2.year) {
    result = 0;
  } else if (elem_1.month > elem_2.month) {
    result = 1;
  } else if (elem_1.month < elem_2.month) {
    result = 0;
  } else if (elem_1.day > elem_2.day) {
    result = 1;
  } else if (elem_1.day < elem_2.day) {
    result = 0;
  } else if (elem_1.hour > elem_2.hour) {
    result = 1;
  } else if (elem_1.hour < elem_2.hour) {
    result = 0;
  } else if (elem_1.minute > elem_2.minute) {
    result = 1;
  } else if (elem_1.minute < elem_2.minute) {
    result = 0;
  } else if (elem_1.second > elem_2.second) {
    result = 1;
  } else if (elem_1.second < elem_2.second) {
    result = 0;
  } else {
    result = 0;
  }
  return result;
}

void sort(FILE *file_pointer) {
  int records_count = get_records_count_in_file(file_pointer);
  int min;
  my_struct min_elem;
  my_struct elem;
  int offset = 0;
  for (int i = 0; i < records_count - 1; i++) {
    min_elem = read_record_from_file(file_pointer, i);
    for (int j = i + 1; j < records_count; j++) {
      elem = read_record_from_file(file_pointer, j);
      min = compare(min_elem, elem);
      if (min) {
        min_elem = elem;
        offset = j;
      }
    }
    fseek(file_pointer, offset * sizeof(my_struct), SEEK_SET);
    swap_records_in_file(file_pointer, i, offset);
  }
}

int menu_input(int *menu_v);
int file_exists(char *file_name);
void print_data(FILE *fp);
void add_record(char *file_name);

int main() {
  int menu;
  char path[500];
  scanf("%s", path);
  if (file_exists(path)) {
    printf("n/a");
  } else {
    if (menu_input(&menu) && menu != 1 && menu != 0 && menu != 2) {
      printf("n\a");
    } else if (menu == -1) {
      exit(0);
    }
    if (menu == 0) {
      FILE *file_ptr;
      file_ptr = fopen(path, "rb+");

      print_data(file_ptr);
      fclose(file_ptr);
    } else if (menu == 1) {
      FILE *file_ptr;
      file_ptr = fopen(path, "rb+");
      sort(file_ptr);
      print_data(file_ptr);
      fclose(file_ptr);
    } else if (menu == 2) {
      add_record(path);
      FILE *fp = fopen(path, "rb+");
      sort(fp);
      print_data(fp);
      fclose(fp);
    }
  }

  return 0;
}

void add_record(char *file_name) {
  FILE *pfile;
  my_struct elem;
  pfile = fopen(file_name, "ab+");
  int records_count = get_records_count_in_file(pfile);
  scanf("%d %d %d %d %d %d %d %d", &elem.year, &elem.month, &elem.day,
        &elem.hour, &elem.minute, &elem.second, &elem.status, &elem.code);
  write_record_in_file(pfile, &elem, records_count);
  fclose(pfile);
}

void print_data(FILE *fp) {
  my_struct elem;
  int records_count = get_records_count_in_file(fp);
  for (int i = 0; i < records_count; i++) {
    elem = read_record_from_file(fp, i);
    printf("%d %d %d %d %d %d %d %d\n", elem.year, elem.month, elem.day,
           elem.hour, elem.minute, elem.second, elem.status, elem.code);
  }
  fclose(fp);
}

int file_exists(char *file_name) {
  int flag = 1;
  FILE *fp;
  fp = fopen(file_name, "rb+");
  if (fp) {
    flag = 0;
    printf("%d", flag);
  }
  fclose(fp);
  return flag;
}

int menu_input(int *menu_v) {
  int flag = 0;
  char c;
  if (scanf("%d%c", menu_v, &c) != 1 && c != '\n') {
    flag = 1;
  }
  return flag;
}

my_struct read_record_from_file(FILE *pfile, int index) {
  int offset = index * sizeof(my_struct);
  fseek(pfile, offset, SEEK_SET);

  my_struct record;
  fread(&record, sizeof(my_struct), 1, pfile);

  rewind(pfile);

  return record;
}

void write_record_in_file(FILE *pfile, const my_struct *record_to_write,
                          int index) {
  int offset = index * sizeof(my_struct);
  fseek(pfile, offset, SEEK_SET);

  fwrite(record_to_write, sizeof(my_struct), 1, pfile);

  fflush(pfile);

  rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
  my_struct record1 = read_record_from_file(pfile, record_index1);
  my_struct record2 = read_record_from_file(pfile, record_index2);

  write_record_in_file(pfile, &record1, record_index2);
  write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
  int size = 0;
  fseek(pfile, 0, SEEK_END);
  size = ftell(pfile);
  rewind(pfile);
  return size;
}

int get_records_count_in_file(FILE *pfile) {
  return get_file_size_in_bytes(pfile) / sizeof(my_struct);
}
