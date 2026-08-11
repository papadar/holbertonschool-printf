#include "main.h"
#include <stdarg.h>

/**
 * _printf - print a string interspersed with other vars
 * @format: pointer to the first character of the string
 * Return: 0 if succesful, anything else is an error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, k;
	void (*func)(va_list arglist);

	va_start(args, format);
	i = 0;
	while (format && format[i])
	{
		if (strcmp(format[i],'%') != 0)
		{
			_putchar(format[i]);
		}
		else 
		{
			func = get_op_func(format[i+1]);
			if (func == NULL)
			{
				exit(99);
			}		
			func()
		}
		i++;
	}
}

int (*get_op_func(char *s))(va_list argList)
{
	op_t ops[] = {
		{"c", printChar},
		{"i", printInt},
		{"d", printFlot},
		{"s", printStr},
		{NULL, NULL}
	};
	int i;

	while (ops[i].op)
	{
		if (strcmp(ops[i].op, s) == 0)
		{
			return (op[i].f);
		}
		i++;
	}
	return (NULL);
}
