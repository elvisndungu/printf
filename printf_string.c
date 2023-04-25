#include "main.h"
/**
 * print_string - print a string :)
 * @args: takes the str it got
 * Return: the length of the string.
 */
int printf_string(va_list args)
{
	char *s;
	int i, len;

	s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
}