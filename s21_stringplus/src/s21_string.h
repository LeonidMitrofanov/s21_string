#pragma once  // Однократное подключение файла

#define S21_NULL ((void *)0)

typedef unsigned long int s21_size_t;

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str
void *s21_memchr(const void *, int, s21_size_t);

// Сравнивает первые n байтов str1 и str2
int s21_memcmp(const void *, const void *, s21_size_t);

// Копирует n символов из src в dest
void *s21_memcpy(void *, const void *, s21_size_t);

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str
void *s21_memset(void *, int, s21_size_t);

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов
char *s21_strncat(char *, const char *, s21_size_t);

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str
char *s21_strchr(const char *, int);

// Сравнивает не более первых n байтов str1 и str2
int s21_strncmp(const char *, const char *, s21_size_t);

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *, const char *, s21_size_t);

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2
s21_size_t s21_strcspn(const char *, const char *);

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке
char *s21_strerror(int);

// Вычисляет длину строки str, не включая завершающий нулевой символ
s21_size_t s21_strlen(const char *);

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2
char *s21_strpbrk(const char *, const char *);

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str
char *s21_strrchr(const char *, int);

// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack
char *s21_strstr(const char *, const char *);

// Разбивает строку str на ряд токенов, разделенных delim
char *s21_strtok(char *, const char *);

// Считывает форматированный ввод из строки
int s21_sscanf(const char *, const char *, ...);

// Отправляет форматированный вывод в строку, на которую указывает str
int s21_sprintf(char *, const char *, ...);

// Возвращает копию строки (str), преобразованной в верхний регистр
void *s21_to_upper(const char *);

// Возвращает копию строки (str), преобразованной в нижний регистр
void *s21_to_lower(const char *);

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src)
void *s21_insert(const char *, const char *, s21_size_t);

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src)
void *s21_trim(const char *, const char *);

// Преобразует строку в значение типа double
long double s21_atof(const char *);

// Преобразует строку в long int
long long s21_strtol(const char *, char **, int);

// Преобразует целое число value в строку string в формате radix
char *s21_itoa(long int, char *, int);

// Преобразует число float или double в строку.
char *s21_ftoa(long double, char *, int);