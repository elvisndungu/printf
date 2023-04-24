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
    int i;
    int j;
    int len;
    
    va_list args;
    convert_match match[] = {
		{"%s", printf_string},
		{"%c", printf_char}
    }
    i = 0; 
    len = 0;
    
    va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	
	Here:
	while (format[i] != '\0')
	{
		j = 0;
		while (j < 13)
		{
			if (_strcmp(match[j].id, &format[i]) == 0)
			{
				len += match[j].f(args);
				i += _strlen(match[j].id);
				goto Here;
			}
			j++;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
    
	va_end(args);
	return (len);
}
