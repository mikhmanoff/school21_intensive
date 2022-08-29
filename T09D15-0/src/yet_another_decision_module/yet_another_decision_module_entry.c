#include "decision.h"

int main() {
    double *data;
    int n;
    if (input(&data, &n)) {
        printf("n/a");
    } else {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    }
    free(data);
    return 0;
}
