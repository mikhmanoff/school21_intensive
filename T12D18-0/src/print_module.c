#include "print_module.h"
#include <stdio.h>

int print_char(char ch) { return putchar(ch); }

void print_log(int (*print)(char), char *message) {
  for (int i = 0; message[i] != 0; i++) {
    print(message[i]);
  }
}
