#include <stdio.h>

int input(int *a, int *n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n = 10, data[n];
    int f = input(data, &n);

    if (f) {
        printf("n/a");
    } else {
        sort(data, n);
        output(data, n);
    }

    return 0;
}

int input(int *a, int *n) {
    int flag = 0, res = 0, c;

    for (int *p = a; p - a < *n; p++) {
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

    return flag;
}

void sort(int *a, int n) {
    int temp;
    for (int *p = a; p < &a[n - 1]; ++p) {  // a + n - 1
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
