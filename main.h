#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct
	{
	const char* id;
	int (*f)();
	} match_maker;

int _printf(const char *format, ...);

int printf_char(va_list args);
int printf_string(va_list args);
int _putchar(char c);
int printf_percent(void);


int _strlen(char *s);
int _strlenc(const char *s);

int print_integer(va_list args);
int print_positive_integer(int num);

#endif
