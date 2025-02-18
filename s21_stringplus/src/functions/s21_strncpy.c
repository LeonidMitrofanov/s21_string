#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  s21_size_t i;

  // Копируем символы из src в dest с учетом n
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  // Если n больше длины src, заполняем оставшуюся часть dest нулями
  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return ptr;
}
