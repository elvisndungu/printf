#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
    typedef struct {
        const char* id;
        int (*f)();
    } convert_match;

    static const convert_match m[] = {
            {"%s", printf_string}, {"%c", printf_char},
            {"%%", printf_percent}
    };
    static const int m_len = sizeof(m) / sizeof(m[0]);

    va_list args;
    int i = 0, len = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            int j, found = 0;
            for (j = 0; j < m_len; j++)
            {
                if (strncmp(m[j].id, format + i, strlen(m[j].id)) == 0)
                {
                    len += m[j].f(args);
                    i += strlen(m[j].id);
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