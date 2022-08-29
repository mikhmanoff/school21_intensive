#include "data_io.h"
#include <stdio.h>
#include <stdlib.h>

int input(double **data, int *n) {
    int res = 0, flag = 0;
    char c;
    if (scanf("%d%c", n, &c) != 1 && *n <= 0 && c != ' ' && c != '\n' && c != EOF) {
        flag = 1;
    } else {
        res = 0;
        flag = 0;
        *data = (double *) malloc (*n * sizeof(double));
        for (int i = 0; i < *n; i++) {
          res += scanf("%lf", &(*data)[i]);
        }
    }
    if (res != *n || *n <= 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", (data)[i]);
    }
    putchar('\b');
}
