#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    int f = input(data, &n);

    if (f) {
        printf("n/a");
    } else {
        output(data, n);
        output_result(max(data, n),
                     min(data, n),
                     mean(data, n),
                     variance(data, n));
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    putchar('\b');
}

int max(int *a, int n) {
    int max = -2147483648;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max; 
}

int min(int *a, int n) {
    int min = 2147483647;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
                       printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
                   }
