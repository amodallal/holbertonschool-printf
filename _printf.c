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
 * print_number - Prints an integer.
 * @n: The integer to print.
 * Return: Number of characters printed.
 */
int print_number(int n)
{
    unsigned int num;
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');
    return (count);
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
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_number(va_arg(args, int));
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
