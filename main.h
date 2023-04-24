#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


int _printf(const char *format, ...);

int printf_char(va_list args);
int printf_string(va_list args);
int _putchar(char c);
int printf_percent(void);

#endif
