#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str) {
  size_t length = 0;
  for (; *(str + length); length++) {
  }
  return length;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

char *strcpy(char *dest, const char *src) {
  char *orig = dest;
  while ((*dest++ = *src++) != '\0') {
  }
  return orig;
}

char *strcat(char *dest, const char *src) {
  char *dst = dest;

  while (*dest != '\0')
    dest++;
  while ((*dest++ = *src++) != '\0') {
  }
  return dst;
}
