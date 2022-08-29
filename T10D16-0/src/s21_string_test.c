#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();

int main() {
#ifdef STRLEN_TESTS
  s21_strlen_test();
#endif

#ifdef STRCMP_TESTS
  s21_strcmp_test();
#endif

#ifdef STRCPY_TESTS
  s21_strcpy_test();
#endif

#ifdef STRCAT_TESTS
  s21_strcat_test();
#endif

  return 0;
}

void s21_strlen_test() {
  char str_norm[] = "Normal values are good!";
  char str_edge[] = "Нормальные значения - это хорошо!";
  char str_unnorm[] = "Normal val\0ues are goo";

  printf("%s\n", str_norm);
  printf("%lu\n", strlen(str_norm));
  if (strlen(str_norm) != 23) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }

  printf("%s\n", str_edge);
  printf("%lu\n", strlen(str_edge));
  if (strlen(str_edge) != 33) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }

  printf("%s\n", str_unnorm);
  printf("%lu\n", strlen(str_unnorm));
  if (strlen(str_unnorm) != 25) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
}

void s21_strcmp_test() {
  char str_norm1[] = "Normal values are good!";
  char str_norm2[] = "Normal values are good!";
  char str_edge1[] = "Нормальные значения - это хорошо!";
  char str_edge2[] = "Нормальные значения - это хорошо!";
  char str_unnorm1[] = "Normal val\0ues are goo";
  char str_unnorm2[] = "Normal val\0ues are goo";

  printf("%s %s\n", str_norm1, str_norm2);
  printf("%s %s\n", str_edge1, str_edge2);
  printf("%s %s\n", str_unnorm1, str_unnorm2);

  printf("%d\n", strcmp(str_norm1, str_norm2));
  printf("%d\n", strcmp(str_edge1, str_edge2));
  printf("%d\n", strcmp(str_unnorm1, str_unnorm2));

  if (strcmp(str_norm1, str_norm2) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  if (strcmp(str_edge1, str_edge2) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  if (strcmp(str_unnorm1, str_unnorm2) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void s21_strcpy_test() {
  char str_norm[] = "Normal values are good!";
  char str_edge[] = "Нормальные значения - это хорошо!";
  char str_unnorm[] = "Normal val\0ues are goo";

  char str_norm_copy[40];
  char str_edge_copy[40];
  char str_unnorm_copy[40];

  strcpy(str_norm_copy, str_norm);
  strcpy(str_edge_copy, str_edge);
  strcpy(str_unnorm_copy, str_unnorm);

  printf("%s\n", str_norm);
  printf("%s\n", str_edge);
  printf("%s\n", str_unnorm);

  printf("%s\n", str_norm_copy);
  printf("%s\n", str_edge_copy);
  printf("%s\n", str_unnorm_copy);

  if (strcmp(str_norm, str_norm_copy) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  if (strcmp(str_edge, str_edge_copy) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  if (strcmp(str_unnorm, str_unnorm_copy) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void s21_strcat_test() {
  char str_norm[] = "Normal values are good!";
  char str_edge[] = "Нормальные значения - это хорошо!";
  char str_unnorm[] = "Normal val\0ues are goo";

  char str_norm_copy[40];
  char str_edge_copy[40];
  char str_unnorm_copy[40];

  printf("%s\n", str_norm);
  printf("%s\n", str_edge);
  printf("%s\n", str_unnorm);

  str_norm[0] = '\0';
  str_edge[0] = '\0';
  str_unnorm[0] = '\0';

  strcat(str_norm_copy, str_norm);
  strcat(str_edge_copy, str_edge);
  strcat(str_unnorm_copy, str_unnorm);

  printf("%s\n", strcat(str_norm, str_norm_copy));
  printf("%s\n", strcat(str_edge, str_edge_copy));
  printf("%s\n", strcat(str_unnorm, str_unnorm_copy));

  if (strlen(str_norm) * 2 != strlen(str_norm_copy)) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  if (strlen(str_edge) * 2 != strlen(str_edge_copy)) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  if (strlen(str_unnorm) * 2 != strlen(str_unnorm_copy)) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}
