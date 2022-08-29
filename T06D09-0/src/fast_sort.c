#include <stdio.h>

int input(int *a, int *n);
void merge_sort(int *a, int n);
void merge_sort_recursion(int *a, int left, int right);
void merge_sorted_arrays(int *a, int n, int m, int r);
void output_merge(int *a, int n);

int main() {
    int n = 10, data[n];
    int f = input(data, &n);

    if (f) {
        printf("n/a");
    } else {
        merge_sort(data, n);
        output_merge(data, n);
    }

    return 0;
}

int input(int *a, int *n) {
    int flag = 0, res = 0, c;
    for (int *p = a; p - a < *n; p++) {
        res += scanf("%d", p);
    }
    while ((c = getchar()) && c != EOF && c != '\n') {
        if (c != ' ') {
            flag = 1;
        }
    }
    if (res != *n || flag) {
        flag = 1;
    }

    return flag;
}

void merge_sort(int *a, int n) {
    merge_sort_recursion(*a, n - 1);
}

void merge_sort_recursion(int *a, int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
    }
}

void merge_sorted_arrays(int *a, int n, int m, int r) {

}

void output_merge(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    putchar('\b');
}
