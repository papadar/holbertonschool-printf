#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, (*func)(va_list arglist);

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (format)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}
		else
		{
			/* Check for % at end of string */
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}

			func = get_op_func(&format[i + 1]);
			/* Check for % followed by unknown specifier */
			if (func == NULL)
			{
				count += _putchar('%');
				count += _putchar(format[i + 1]);
			}
			else
			{
				count += func(args);
			}
			i += 2;
		}
	}

	va_end(args);
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
