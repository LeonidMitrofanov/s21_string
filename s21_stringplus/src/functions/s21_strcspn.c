#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  while (*str1) {
    const char *ptr = str2;
    while (*ptr) {
      if (*str1 == *ptr) {
        return count;
      }
      ptr++;
    }
    str1++;
    count++;
  }
  return count;
}