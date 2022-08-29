#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *shift);
void right_shift(int *buffer, int length, int shift);
void left_shift(int* buffer, int length, int shift);
void output(int *buffer, int length);

int main() {
    int f, n, shift_v, data[NMAX];
    f = input(data, &n, &shift_v);
    if (f) {
        printf("n/a");
    } else {
        if (shift_v < 0) {
            right_shift(data, n, shift_v);
        } else if (shift_v > 0) {
            left_shift(data, n, shift_v);
        }
        output(data, n);
    }
}

int input(int *buffer, int *length, int *shift) {
    int flag = 0, res = 0, c;
    res = scanf("%d", length);
    while ((c = getchar()) && c != EOF && c != '\n') {
        if (c != ' ') {
            flag = 1;
        }
    }
    if (res != 1 || flag || *length == 0 || *length > NMAX) {
        flag = 1;
    } else {
        flag = 0;
        res = 0;
        for (int *p = buffer; p - buffer < *length; p++) {
            res += scanf("%d", p);
        }
        while ((c = getchar()) && c != EOF && c != '\n') {
            if (c != ' ') {
                flag = 1;
            }
        }
        if (res != *length || flag || *length > NMAX) {
            flag = 1;
        }
        res = 0;
        flag = 0;
        res = scanf("%d", shift);
        while ((c = getchar()) && c != EOF && c != '\n') {
            if (c != ' ') {
                flag = 1;
            }
        }
    }
    return flag;
}

void left_shift(int *buffer, int length, int shift) {
    for (int i = 0; i < shift; i++) {
        for (int i = 0; i < shift; i++) {
            for (int *p = buffer; p - buffer < length; ++p) {
                for (int *q = buffer; p - buffer < length; ++p) {
                    int temp = *p;
                    *p = *q;
                    *q = temp;
                }
            }
        }
    }
}

// void swap(int a, int b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

void right_shift(int* buffer, int length, int shift) {
    for (int i = 0; i < -shift; i++) {
        for (int *p = buffer; p - buffer < length; ++p) {
            for (int *q = buffer; p - buffer < length; ++p) {
                int temp = *q;
                *q = *p;
                *p = temp;
            }
        }
    }
    printf("\n");
}

void output(int *buffer, int length) {
    printf("\n");
    printf("\n");
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d ", *p);
    }
    putchar('\b');
}
