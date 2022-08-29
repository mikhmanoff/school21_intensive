#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 10000

int menu_input(int *menu_v);
int file_exists(char *filen);
void read_from_file(char *filen);
void add_to_file(char *filen);
void print_error();

int main() {
  int menu = 0;
  char file_n[MAX_CHAR];
  while (menu != -1) {
    if (menu_input(&menu)) {
      print_error();
      fflush(stdin);
      menu = 0;
    }

    if (menu == 1) {
      scanf("%s", file_n);
      if (file_exists(file_n)) {
        print_error();
      } else {
        read_from_file(file_n);
        printf("\n");
      }
    }

    if (menu == 2) {
      if (file_exists(file_n)) {
        print_error();
      } else {
        add_to_file(file_n);
        read_from_file(file_n);
        printf("\n");
        exit(0);
      }
    }
  }
  return 0;
}

void add_to_file(char *filen) {
  char c[MAX_CHAR] = {0};
  int i = 0, ch;
  while ((ch = getchar()) != '\n') {
    c[i] = ch;
    i++;
  }

  FILE *filep;
  filep = fopen(filen, "a+");
  if (filep) {
    fprintf(filep, "\n");
    fprintf(filep, c);
    fclose(filep);
  }
}

int menu_input(int *menu_v) {
  int flag = 0;
  char c;
  if (scanf("%d%c", menu_v, &c) != 1 && c != '\n') {
    flag = 1;
  }
  return flag;
}

int file_exists(char *filen) {
  int flag = 1;
  FILE *filep;
  filep = fopen(filen, "r");
  if (filep) {
    flag = 0;
  }
  fclose(filep);
  return flag;
}

void read_from_file(char *filen) {
  int c;
  FILE *filep;
  filep = fopen(filen, "r");
  if (filep) {
    while ((c = getc(filep)) != EOF)
      putchar(c);
    fclose(filep);
  }
}

void print_error() { printf("n/a\n"); }
