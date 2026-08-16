#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function to print a variable amount of characters
 * @format: va_list of arguments that are parsed
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, (*func)(va_list arglist);

	va_start(args, format);

	if (format == NULL)
	}
		_putchar('\n');
		return (0);
	}
	while (format && format[i])
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

			/* find matching func */
			func = get_op_func(&format[i + 1]);

			/* check if func was found */
			if (func != NULL)
			{
				count += func(args);
				i += 2;/* skips '%' + specifier */
			}
			/* if format[i + 1] isnt a valid spcifier, print literal */
			else
			{
				/* unknown specifier -> print '%' and char literal */
				count += _putchar(format[i]);
				count += _putchar(format[i + 1]);
				i += 2;
			}
		}
	}
	va_end(args);
	return(count);
}

/**
 * get_op_func - determines the appropriate function based on char comparison
 * @s: pointer to a char to compare
 * Return: function pointer to match char type
 */

int (*get_op_func(const char *s))(va_list argList)
{
	int i = 0;
	op_t ops[] = 
	{
		{'c', printChar},
		{'%', printPerc},
		{'i', printInt},
		{'d', printInt},
		{'s', printStr},
		{'u', printUSInt},
		{'o', printOct},
		{'x', printHex},
		{'X', printHex},
		{'\0', NULL}
	};

	while (ops[i].op != '\0')
	{
		if (ops[i].op == *s)
		{
			return ops[i].f;
		}
		i++;
	}
	return (NULL);
}
