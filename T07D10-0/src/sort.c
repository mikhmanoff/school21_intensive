#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
  int *data = NULL;
  int n = 10;
  int f = input(&data, &n);

  if (f) {
    printf("n/a");
  } else {
    sort(data, n);
    output(data, n);
  }
  free(data);
  return 0;
}

int input(int **a, int *n) {
  int flag = 0, res = 0, c;
  res = scanf("%d", n);
  while ((c = getchar()) && c != EOF && c != '\n') {
    if (c != ' ') {
      flag = 1;
    }
  }
  if (res != 1 || flag || *n <= 0 || *n > 10) {
    flag = 1;
  } else {
    flag = 0, res = 0;
    *a = (int *)malloc(*n * sizeof(int));
    for (int *p = *a; p - *a < *n; p++) {
      res += scanf("%d", p);
    }
    while ((c = getchar()) && c != EOF && c != '\n') {
      if (c != ' ') {
        flag = 1;
      }
    }
    if (res != *n || flag) {
      flag = 1;
    }
  }

  return flag;
}

void sort(int *a, int n) {
  int temp;
  for (int *p = a; p < &a[n - 1]; ++p) {
    for (int *q = &p[1]; q < &a[n]; ++q) {
      if (*p > *q) {
        temp = *p;
        *p = *q;
        *q = temp;
      }
    }
  }
}

void output(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    printf("%d ", *p);
  }
  putchar('\b');
}
