#include "main.h"

/**
 * _printf - Function that produces output according to a format.
 * @format: Format to print
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	int (*fun)(va_list args);

	va_list args;

	va_start(args, format);
	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;

				fun = get_specifier_handler(format[i]);
				printed_chars += fun(args);

			} else
			{
				_putchar(format[i]);
				printed_chars++;
			}

			i++;
		}
	} else
	{
		return (-1);
	}

	va_end(args);

	return (printed_chars);
}
