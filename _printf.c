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
			{"%s", printf_string}, {"%c", printf_char}, {"%%", printf_percent},
			{"%d", printf_integer}, {"%i", printf_integer}
	};
	int len = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			int found = 0;

			for (int j = 0; j < sizeof(match) / sizeof(match[0]); j++)
			{
				if (strncmp(match[j].id, format + i, strlen(match[j].id)) == 0)
				{
					len += match[j].f(args);
					i += strlen(match[j].id) - 1;
					found = 1;
					break;
				}
			}
			if (!found)
				len += _putchar(format[i]);
		}
		else
			len += _putchar(format[i]);
	}
	va_end(args);
	return (len);
}
