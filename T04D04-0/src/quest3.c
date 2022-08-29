#include <stdio.h>

int fibo(int a);

int main() {
  int a;
  char c;
  int result;

  if (scanf("%d%c", &a, &c) == 2 && c == '\n') {
    for (int i = 1; i <= a; i++) {
      result = fibo(i);
    }
    printf("%d", result);
  } else {
    printf("n/a");
  }

  return 0;
}

int fibo(int a) {
  if (a == 1 || a == 2) {
    return 1;
  }
  return fibo(a - 1) + fibo(a - 2);
}
