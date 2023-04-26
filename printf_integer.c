#include "main.h"
/**
 * printf_integer - prints an integer to stdout
 * @args: the va_list containing the integer to print
 *
 * Return: the number of characters printed
 */
int printf_integer(va_list args)
{
	int num = va_arg(args, int);
	int length = 0;

	if (num == 0)
	{
		_putchar('0');
		length = 1;
	}

	else if (num < 0)
	{
		_putchar('-');
		length = printf_positive_integer(-num);
		length += 1;
	}
	else
	{
		length = printf_positive_integer(num);
	}

	return (length);
}

/**
 * printf_positive_integer - prints the absolute value of an integer to stdout
 * @num: the integer to print
 *
 * Return: the number of characters printed
 */
int printf_positive_integer(int num)
{
	int length = 0;

	if (num / 10)
	{
		length = printf_positive_integer(num / 10);
	}

	/* betty patch */
	_putchar((num % 10) + '0');
	length += 1;

	return (length);
}