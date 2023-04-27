#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

typedef struct
	{
	const char *id;
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
int printf_dec(va_list args);


/* task 02 */
int printf_binary(va_list val);


/* task 03 */
int printf_unsigned(va_list args);
int printf_octal(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);


/* task 04
 * 100 */


/* task 05 */
int printf_special_string(va_list args);
int printf_HEX_two(unsigned int num);

/* task 06 */
int printf_hex_three(unsigned long int num);
int printf_pointer(va_list args);


/* task 07 */
int printf_rev(va_list args);

/* task 14 */
int ROT13(va_list args);

/* task 15 */
/*
 * 7%
 */


#endif
