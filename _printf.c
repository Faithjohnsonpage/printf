#include "main.h"

/**
 * print_char - Print a character.
 * @c: The character to print.
 *
 * Return: 1 on success, -1 on failure.
 */
int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Print a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_str(char *str)
{
	int count = 0;

	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
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

	if (specifier == 'c')
		count += print_char(va_arg(mynum, int));
	else if (specifier == 's')
		count += print_str(va_arg(mynum, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(mynum, int), 10);
	else if (specifier == '%')
		count += print_char('%');
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
