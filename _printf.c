#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a single character to stdout.
 * @c: The character to print.
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing specifiers.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
	return (-1);

	va_start(args, format);

	while (format[i])
	{
	if (format[i] == '%')
	{
	i++;
	if (!format[i])
	return (-1);
	if (format[i] == 'c')
	count += _putchar(va_arg(args, int));
	else if (format[i] == 's')
	{
	char *str = va_arg(args, char *);
	if (!str)
	str = "(null)";
	while (*str)
	count += _putchar(*str++);
	}
	else if (format[i] == '%') 
	count += _putchar('%');
	else
	{
	count += _putchar('%');
	count += _putchar(format[i]);
	}
	}
	else
	count += _putchar(format[i]);
	i++;
	}
	va_end(args);
	return (count);
}
