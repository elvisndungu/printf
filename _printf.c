#include "main.h"
#include <stdlib.h>
#include <string.h>


/**
 * match_identifier - Matches an identifier in the format string
 * @format: The format string to parse
 * @match: The array of match_maker structs to match against
 * @m_len: The length of the match array
 * @i: The current index in the format string
 * Return: The index of the match in the match array, or -1 if not found
 */
int match_identifier(const char *format, const match_maker *match, const int m_len, int i)
{
    for (int j = 0; j < m_len; j++)
    {
        if (strncmp(match[j].id, format + i, strlen(match[j].id)) == 0)
            return j;
    }
    return -1;
}

/**
 * _printf - Mother Function Calls other functions.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *const format, ...) {
    static const match_maker match[] = {
            {"%s", printf_string},
            {"%c", printf_char},
            {"%%", printf_percent},
            {"%d", printf_integer},
            {"%i", printf_integer},
    };
    static const int m_len = sizeof(match) / sizeof(match[0]);

    va_list args;
    int i = 0, len = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0') {
        if (format[i] == '%') {
            int match_idx = match_identifier(format, match, m_len, i);
            if (match_idx != -1) {
                len += match[match_idx].f(args);
                i += strlen(match[match_idx].id);
            } else {
                len += _putchar(format[i]);
                i++;
            }
        } else {
            len += _putchar(format[i]);
            i++;
        }
    }
    va_end(args);
    return (len);
}