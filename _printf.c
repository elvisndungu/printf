#include "main.h"
/**
 * m_identfy - Matches an identifier in the format string
 * @format: The format string to parse
 * @match: The array of m_maker structs to match against
 * @m_len: The length of the match array
 * @i: The current index in the format string
 * Return: The index of the match in the match array, or -1 if not found
 */
int m_identfy(const char *format, const m_maker *match, const int m_len, int i)
{
	int j;

	for (j = 0; j < m_len; j++)
	{
		if (strncmp(match[j].id, format + i, strlen(match[j].id)) == 0)
			return (j);
	}
	return (-1);
}

/**
 * _printf - Mother Function Calls other functions.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
static const m_maker match[] = {{"%s", printf_string}, {"%c", printf_char},
{"%%", printf_percent},{"%d", printf_integer}, {"%i", printf_integer},
{"%b", printf_binary}, {"%u", printf_unsigned}, {"%u", printf_octal},
{"%x", printf_hex},{"%X", printf_HEX}, {"%S", printf_special_string},
{"%p", printf_pointer}, {"%r", printf_rev}, {"%R", ROT13}
};
	static const int m_len = sizeof(match) / sizeof(match[0]);
	va_list args;
	int i = 0, len = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			int match_idx = -1;

			match_idx = m_identfy(format, match, m_len, i);
			if (match_idx >= 0)
			{
				len += match[match_idx].f(args);
				i += strlen(match[match_idx].id);
			}
			else
			{
				len += _putchar(format[i]);
				i++;
			}
		}
		else
		{
			len += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
