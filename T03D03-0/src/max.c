#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b, max_num;
    char c;

    if (scanf("%d %d%c", &a, &b, &c) == 3 || c == '\n')
        if (a != b) {
            max_num = max(a, b);
            printf("%d\n", max_num);
        } else {
            printf("Числа равны\n");
        }
    else
        printf("n/a\n");
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
