#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct
	{
	const char* id;
	int (*f)();
	} m_maker;

/* mother function */
int _printf(const char *format, ...);

/* util functions */
int _putchar(char c);

/* task 00 */
int _strlen(char *s);
int _strlenc(const char *s);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_percent(void);

/* task 01 */
int printf_integer(va_list args);
int printf_positive_integer(int num);


/* task 02 */
int printf_binary(va_list val);

/* task 03 */
int printf_unsigned(va_list args);
int printf_octal(va_list val);

#endif
