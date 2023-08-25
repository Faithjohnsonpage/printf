#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int print_digit(long n, int base);
int print_format(char specifier, va_list mynum);


#endif
