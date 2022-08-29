/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
double sigma(int *a, int n);

void output_result(double mean_v,
                   double sigma_v,
                   int *a, int n);

int main() {
    int n, data[NMAX];
    int f = input(data, &n);

    if (f) {
        printf("n/a");
    } else {
        output_result(mean(data, n),
                     sigma(data, n),
                     data, n);
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
    if (res != 1 || flag) {
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
        if (res != *n || flag || *n > NMAX) {
            flag = 1;
        }
    }
    return flag;
}

double sigma(int *a, int n) {
    double mean_n = mean(a, n);
    double variance_n = variance(a, n);
    double res = mean_n + 3 * sqrt(variance_n);
    return res;
}

double mean(int *a, int n) {
    double sum = 0.;
    for (int *p = a; p - a < n; p++) {
        sum += (double) *p;
    }

    return sum / n;
}

double variance(int *a, int n) {
    double math_expect = mean(a, n);
    double sum = 0.;
    for (int *p = a; p - a < n; p++) {
        sum += ((double) *p - math_expect) * ((double) *p - math_expect);
    }
    return sum / n;
}

void output_result(double mean_v,
                   double sigma_v,
                   int *a, int n) {
                       int res = 0;
                       for (int *p = a; p - a < n; p++) {
                           if (*p % 2 == 0 &&
                           *p >= mean_v &&
                           *p <= sigma_v &&
                           *p != 0) {
                               res = *p;
                           }
                        }
                       printf("%d", res);
                   }
