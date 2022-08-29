#include <stdio.h>

int del(int a, int b);
int simple(int a);

int main() {
  int a = 0;
  int result = 2;
  char c;

  if (scanf("%d%c", &a, &c) == 2 && c == '\n') {
    if (a < 0) {
      a = a * -1;
    }
    for (int i = 2; i <= a; i++) {
      if (del(a, i) == 1 && simple(i) == 1) {
        result = i;
      }
    }

    printf("%d", result);
  } else {
    printf("n/a");
  }
}

int del(int a, int b) {

  while (a >= b) {
    a -= b;
  }
  if (a + b == 0)
    return 1;

  return 0;
}

int simple(int a) {
  for (int i = 2; i < a; i++) {
    if (del(a, i)) {
      return 0;
    }
  }
  return 1;
}
