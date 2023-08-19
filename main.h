#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <stddef.h>

#define UNUSED(x) (void)(x)

/**
 * struct specifiers_struct - Specifiers structure
 *
 * @spc: Specifier
 * @spc_handler: The function to handel specifier
 */
typedef struct specifiers_struct
{
	char spc;

	int (*spc_handler)(va_list args);

} spc_t;

int _putchar(char c);

int _printf(const char *format, ...);

int handel_char(va_list args);

int handel_percent(va_list args);

int handel_string(va_list args);

int (*get_specifier_handler(char spc))(va_list args);

#endif
