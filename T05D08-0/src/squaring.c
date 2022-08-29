#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
    } else {
        squaring(data, n);
        output(data, n);
    }

    return 0;
}

int input(int *a, int *n) {
    int flag = 0, res = 0, c;
    res = scanf("%d", n);
    while ((c = getchar()) && c != EOF && c != '\n') {
        if (c != ' ') {
            flag = 1;
        }
    }

    if (res != 1 || flag == 1) {
        flag = 1;
    } else {
        flag = 0;
        res = 0;
        for (int *p = a; p - a < *n; p++) {
            res += scanf("%d", p);
        }

        while ((c = getchar()) && c != EOF && c != '\n') {
            if (c != ' ') {
                flag = 1;
            }
        }
        if (res != *n || flag == 1 || *n > NMAX) {
            flag = 1;
        }
    }
    return flag;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    putchar('\b');
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
