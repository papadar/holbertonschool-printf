#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/**
 * _printf - print a string interspersed with other vars
 * @format: pointer to the first character of the string
 * Return: 0 if succesful, anything else is an error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, k;
	int (*func)(int n, va_list arglist);

	va_start(args, format);
	i = j = 0;
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else 
		{
			j++;
			func = get_op_func(&format[i + 1]);
			if (func == NULL)
			{
				exit(99);
			}		
			func(j, args);
		}
		i++;
	}
}

int (*get_op_func(const char *s))(int n, va_list argList)
{
        op_t ops[] = {
                {"c", printChar},
                {"i", printInt},
                {"d", printFlot},
                {"s", printStr},
                {NULL, NULL}
        };
        int i = 0;

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

int printChar(int n, va_list charList)
{
	/*_putchar(charList[n]);*/
	return (0);
}

int printStr(int n, va_list strList)
{
	/*_putchar(strList[n]);*/
	return (0);
}

int printInt(int n, va_list intList)
{
        /*_putchar(intList[n]);*/
	return (0);
}

int printFlot(int n, va_list flotList)
{
	/*_putchar(flotList[n]);*/
	return (0);
}	
