#include <stdarg.h>
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

	va_list args;

	va_start(args, format);
	if (format)
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;

				if (format[i] == 'c')
					printed_chars += handel_char(args);

				if (format[i] == 's')
					printed_chars += handel_string(args);

				if (format[i] == '%')
					printed_chars += handel_percent(args);

			} else
			{
				_putchar(format[i]);
				printed_chars++;
			}

			i++;
		}

	va_end(args);

	return (printed_chars);
}
