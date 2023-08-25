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
