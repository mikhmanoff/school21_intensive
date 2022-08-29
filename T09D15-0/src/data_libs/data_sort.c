#include "data_sort.h"

void sort(double *data, int n) {
  double temp;
  for (double *p = data; p < &data[n - 1]; ++p) {
    for (double *q = &p[1]; q < &data[n]; ++q) {
      if (*p > *q) {
        temp = *p;
        *p = *q;
        *q = temp;
      }
    }
  }
}
