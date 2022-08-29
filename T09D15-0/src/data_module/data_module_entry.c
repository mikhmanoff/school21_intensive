#include "data_process.h"

int main() {
    double *data = NULL;
    int n;
    // Don`t forget to allocate memory !

    if (input(&data, &n)) {
        printf("n/a");
    } else {
        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");
    }
    free(data);
    return 0;
}
