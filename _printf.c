#include "main.h"
#include <stdarg.h>

/**
 * _printf - mother function that will pick the correct function
 * @format: identifier to look for
 * Return: the len of the string
 */

int _printf(const char *format, ...)
{
	int str_len = 0;

	va_list args;
	va_start(args, format);

	while (*format != '\0')
{
	/*
	 * If format specifier eg '%d' then begin search
	 */

	if (*format == '%')
        {
            format++;

	    /* 
	     * Switch tht decides whch function to call
	     */

	    switch (*format)
            {

		case 'c':
                    str_len += printf_char(args);
                    break;

		case 's':
                    str_len += printf_string(args);
                    break;
		
		default:
		    return -1;
	    }

	}

	else
        {
            str_len++;
            _putchar(*format);
        }

	va_end(args);
	return str_len;
}

	
}
