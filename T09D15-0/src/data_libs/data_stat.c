#include "data_stat.h"

double max(double *data, int n) {
    double max_v = -2147483648.;
    for (int i = 0; i < n; i++) {
        if ((data)[i] > max_v) {
            max_v = (data)[i];
        }
    }
    return max_v;
}

double min(double *data, int n) {
    double min_v = 2147483647.;
    for (int i = 0; i < n; i++) {
        if ((data)[i] < min_v) {
            min_v = (data)[i];
        }
    }
    return min_v;
}

double mean(double *data, int n) {
    double sum = 0.;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum / n;
}

double variance(double *data, int n) {
    double math_expect = mean(data, n);
    double sum = 0.;
    for (int i = 0; i < n; i++) {
        sum += (data[i] - math_expect) * (data[i] - math_expect);
    }
    return sum / n;
}
