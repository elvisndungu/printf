#include "main.h"
/**
 * print_string - print a string :)
 * @args: takes the str it got
 * Return: the length of the string.
 */
int printf_string(va_list args)

{
	const char *str = va_arg(args, const char *);
    
	if (str == NULL)
{
	return fputs("(null)", stdout);
}
	int count = 0;
    
	while (*str != '\0')
{
	putchar(*str);
	str++;
	count++;
	}
	
return count;
}
