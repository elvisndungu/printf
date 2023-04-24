#include "main.h"
#include <stdarg.h>

/**
 * struct convert_match - structure for conversion matching
 * @id: identifier to match
 * @f: conversion function
 */
typedef struct convert_match
{
	char *id;
	int (*f)(va_list);
} convert_match;

/**
 * _printf - mother function that will pick the correct function
 * @format: identifier to look for
 * Return: the len of the string
 */

int _printf(const char *format, ...)
{
	int i = 0, j, len = 0; 
	va_list args;
	int num_matches;

    	convert_match match[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_percent}
    };

	num_matches = sizeof(match) / sizeof(match[0]);
	

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	
	Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (match[j].id[0] == format[i] && match[j].id[1] == format[i + 1])
			{
				len += match[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
