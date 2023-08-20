#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * len_number - function to get length of number
 * @number: the number
 * Return: length
 */
int len_number(int number)
{
if (number == 0)
{
return (1);
}
int length = 0;
while (number != 0)
{
number /= 10;
length++;
}
return (length);
}
/**
 * handle_number - function to handle different case of integer
 * @number: the number
 *
 * Return:result
 */
int handle_number(int number)
{
if (number == -2147483648)
{
_putchar('-');
_putchar('2');
handle_number(147483648);
return (1);
}
else if (number < 0)
{
_putchar('-');
number = -number;
}
if (number >= 10)
{
handle_number (number / 10);
handle_number (number % 10);
}
else if (number < 10)
{
_putchar(number + '0');
}
}
/**
 * _printf - function that produces output according to a format
 * @format: format
 * @...: the list
 * Return: result
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
if (!format || !format[0])
return (-1);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'd' || *format == 'i')
{
int number = va_arg(args, int);
if (number < 0)
count++;
count += len_number(number);
handle_number(number);
}
else
{
_putchar('%');
count++;
if (*format)
{
_putchar(*format);
count++;
}
}
format++;
}
else
{
_putchar(*format);
format++;
count++;
}
}
va_end(args);
return (count);
}
