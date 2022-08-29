#include <math.h>
#include <stdio.h>

float some_func(float x);

int main() {
    float x, result;
    char c;

    if (scanf("%f%c", &x, &c) == 2 || c == '\n') {
        result = some_func(x);
        printf("%.1f", result);
    } else {
        printf("n/a");
    }

    return 0;
}

float some_func(float x) {
    float deg1 = 7e-3 * powf(x, 4);
    float deg2 = ((powf(x, 1 / 3) * 22.8 - 1e3) * x + 3) / (x * x / 2);
    float deg3 = x * (powf(10 + x, (2 / x)));
    float result = deg1 + deg2 - deg3 - 1.01;

    return result;
}
