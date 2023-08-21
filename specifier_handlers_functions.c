#include <stdarg.h>
#include "main.h"

/**
 * handel_char - Function that handel char specifier.
 * @args: Arguments
 *
 * Return: the number of characters handled
 */
int handel_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * handel_percent - Function that handel percent.
 * @args: Arguments
 *
 * Return: the number of characters handled
 */
int handel_percent(va_list args)
{
	UNUSED(args);

	_putchar('%');
	return (1);
}

/**
 * handel_string - Function that handel string specifier.
 * @args: Arguments
 *
 * Return: the number of characters handled
 */
int handel_string(va_list args)
{
	int i = 0;
	char *s = va_arg(args, char *);

	if (!s)
	{
		s = "(null)";
	}

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}

/**
 * handel_d_i - Function that handel number.
 * @args: Arguments
 *
 * Return: the number of characters handled
 */
int handel_d_i(va_list args)
{
	int number = va_arg(args, int);

	handel_number(number);

	return (number_len(number));
}

/**
 * handel_unknown - Function that handel unknown specifier.
 * @spc: specifier
 *
 * Return: the number of characters handled
 */
int handel_unknown(char spc)
{
	if (spc == ' ')
		return (-1);

	_putchar('%');
	_putchar(spc);

	return (2);
}
