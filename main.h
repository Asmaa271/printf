#ifndef MAIN
#define MAIN

#define UNUSED(x) (void)(x)

/**
 * struct specifiers - Specifiers structure
 *
 * @specifier: Specifier
 * @specifier_handler: The function to handel specifier
 */
typedef struct specifiers
{
	char specifier;

	int (*specifier_handler)(va_list args);

} specifiers;

int _putchar(char c);

int _printf(const char *format, ...);

int handel_char(va_list args);

int handel_percent(va_list args);

int handel_string(va_list args);

#endif
