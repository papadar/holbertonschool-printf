#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - print a string interspersed with other vars
 * @format: pointer to the first character of the string
 * Return: 0 if succesful, anything else is an error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;
	int (*func)(va_list arglist);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		/*	printf("a\n");*/
		}
		else 
		{
			func = get_op_func(&format[i + 1]);
			count += func(args);
			i += 2;
		/*	printf("b\n");*/
		}
	}
	return (count);
}

int (*get_op_func(const char *s))(va_list argList)
{
	op_t ops[] = {
                {'c', printChar},
                {'i', printInt},
                {'d', printInt},
                {'s', printStr},
		{'R', printRepeat},
		{'\0', NULL}
        };
        int i = 0;

        while (ops[i].op != '\0')
        {
		if (ops[i].op == *s)
                {
                        /*printf("the char is%c&\n",*s);*/
			return (ops[i].f);
                }
		i++;
        }
        return (NULL);
}

int printRepeat(va_list repeatList)
{
	return (1);

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
	{
		count += _putchar(str[i]);	
		i++;
	}
	return (count);
}

int printInt(va_list intList)
{
        int count = 0;
	int num = va_arg(intList, int);
	int abs_num;
	int tmp;
	int n = 1;

	printf("num = %d\n", num);

	if (num < 0)
	{
	/*	count += _putchar('-');*/
		abs_num = (-1 * num);
	}
	else
		abs_num = num;
	
	while (abs_num / 10 > 0)
	{	
		tmp = abs_num;
		while (tmp / 10 > 10)
		{
			tmp = tmp / 10;
		}
		count += _putchar(tmp + '0');
	}
	/* while a mod of abs_num > 10 ()*/
	return (count);
}

int printFlot(va_list flotList)
{
	/*_putchar(flotList[n]);*/
	return (0);
}	
