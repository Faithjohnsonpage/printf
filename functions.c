#include "main.h"

/**
 * print_digit - Print a number in the given base.
 * @n: The number to print.
 * @base: The base in which to print the number.
 *
 * Return: The number of characters printed.
 */

int print_digit(long n, int base)
{
	int count = 0;
	char *symbols = "0123456789";

	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (write(1, &symbols[n], 1));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

/**
 * print_format - Print a formatted value based on the specifier.
 * @specifier: The format specifier.
 * @mynum: The va_list containing the argument list.
 *
 * Return: The number of characters printed.
 */

int print_format(char specifier, va_list mynum)
{
	int count = 0;

	if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(mynum, int), 10);
	else
		count += write(1, &specifier, 1);

	return (count);
}


/**
 * _printf - Custom printf function supporting limited format specifiers.
 * @format: The format string.
 * @...: Additional arguments based on format specifiers.
 *
 * Return: The total number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list mynum;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(mynum, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_format(*(++format), mynum);
		}
		else
		{
			count += write(1, format, 1);
			++format;
		}
	}
	va_end(mynum);

	return (count);
}
