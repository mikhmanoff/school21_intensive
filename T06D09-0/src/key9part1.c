/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX];
    int output_data[NMAX] = {}, f;
    f = input(data, &n);
    if (f) {
        printf("n/a");
    } else {
        int sum_v = sum_numbers(data, n);
        if (sum_v == -2147483647) {
            printf("n/a");
        } else {
            int n_output = find_numbers(data, n, n, output_data);
            if (n_output < 0) {
                printf("n/a");
            } else {
                printf("%d\n", sum_v);
                output(output_data, n_output);
            }
        }
    }
}

int input(int *buffer, int *length) {
    int flag = 0, res = 0, c;
    res = scanf("%d", length);
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
        for (int *p = buffer; p - buffer < *length; p++) {
            res += scanf("%d", p);
        }
        while ((c = getchar()) && c != EOF && c != '\n') {
            if (c != ' ') {
                flag = 1;
            }
        }
        if (res != *length || flag) {
            flag = 1;
        }
    }
    return flag;
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0, num = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            num++;
        }
    }

    if (sum == 0 && num == 0) {
        sum = -2147483647;
    }
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
    int sum_v = sum_numbers(buffer, length);
    number = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && sum_v % *p == 0) {
            *numbers = *p;
            number++;
            numbers++;
        }
        
    }
    return number;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d ", *p);
    }
    putchar('\b');
}
