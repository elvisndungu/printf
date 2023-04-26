#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _printf - Mother Function Calls other functions.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	static const match_maker match[] = {
			{"%s", printf_string}, {"%c", printf_char}, {"%%", printf_percent}, {"%d", print_integer},
			{"%i", print_integer},
	};
	int i = 0, len = 0, j, found = 0;
	static const int m_len = sizeof(match) / sizeof(match[0]);
	va_list args;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			for (j = 0; j < m_len; j++)
			{
				if (strncmp(match[j].id, format + i, strlen(match[j].id)) == 0)
				{
					len += match[j].f(args);
					i += strlen(match[j].id);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				_putchar(format[i]);
				len++;
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
