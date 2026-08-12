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
	int i, k;
	int (*func)(va_list arglist);

	va_start(args, format);
	i = 0;
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else 
		{
			func = get_op_func(&format[i + 1]);
			if (func == NULL)
			{
				exit(99);
			}		
			func(args);
		}
		i++;
	}
}

int (*get_op_func(const char *s))(va_list argList)
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
                        return (ops[i].f);
                }
                i++;
        }
        return (NULL);
}

int printChar(va_list charList)
{
	char c = (char)va_arg(charList, int);
	return (_putchar(c));
}

int printStr(va_list strList)
{
	char *str;
	int i, count;

	str = va_arg(strList, char *);
	i = count = 0;

	if (str == NULL)
		str = "(nil)";

	while (str[i] != '\0')
	       count += _putchar(str[i]);	

	return (0);
}

int printInt(va_list intList)
{
        int count = 0;
	int num = va_arg(intList, int);
	unsigned int abs_num;

	if (num < 0)
	{
		count += _putchar('-');
		abs_num = (unsigned int)(-1 * num);
	}
	else
		abs_num = (unsigned int)num;
	
	if (abs_num / 10) {
		count += _putchar((abs_num / 10) + '0');
	}
	count += _putchar((abs_num % 10) + '0');
	return (count);
}

int printFlot(va_list flotList)
{
	/*_putchar(flotList[n]);*/
	return (0);
}	
