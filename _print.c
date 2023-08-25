#include "main.h"
/**
 * _printf - function produces output according to a format
 * @format: a string that contains the text to be written
 * @...: a variable number of arguments
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	va_list mycharacters;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(mycharacters, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(mycharacters, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 'd' || *format == 'i')
				count += print_digit(va_arg(mycharacters, int), 10);
			else if (*format == 's')
			{
				char *str = va_arg(mycharacters, char *);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				count += str_len;
			}
		}
		format++;
	}
	va_end(mycharacters);
	return (count);
}
