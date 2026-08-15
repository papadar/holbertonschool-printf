#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, (*func)(va_list arglist);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}
		else
		{
			/* edge case needed for two %% in a row */
			func = get_op_func(&format[i + 1]);
			count += func(args);
			i += 2;
		}
	}
	return(count);
}

int (*get_op_func(const char *s))(va_list argList)
{
	op_t ops[] = 
	{
		{'c', printChar},
		{'i', printInt},
		{'d', printInt},
		{'s', printStr},
		{'u', printUSInt},
		{'o', printOct},
		{'x', printHex},
		{'X', printHex},
		{'\0', NULL}
	};

	for (int i = 0; ops[i].op != '\0'; i++)
	{
		if (ops[i].op == *s)
		{
			return ops[i].f;
		}
	}
	return (NULL);
}
