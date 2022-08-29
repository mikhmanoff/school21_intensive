#include <stdio.h>

float circle(float a, float b);

int main() {
    float a, b, circle;
    char c;

    if (scanf("%f %f%c", &a, &b, &c) == 3 && c == '\n') {
        circle = circle(a, b);

        if (circle <= 25.) {
            printf("GOTCHA");
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

float circle(float a, float b) { return a * a + b * b; }
