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
		return (0);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}
		else
		{
			if (format[i + 1] == '%' || format[i + 1] == '\0')
			{
				count += _putchar(format[i]);
				i++;
			}
			else
			{
				func = get_op_func(&format[i + 1]);
				count += func(args);
				i += 2;
			}
		}
	}
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
