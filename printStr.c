#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * printStr - receives a string location, and prints each character
 * @strList: va_list containing a string
 * Return: the number of characters that were printed
 */

int printStr(va_list strList)
{
	int i, count = 0;
	char *str = va_arg(strList, char *);
	char nil[7] = {'(','n','u','l','l',')','\0'};

	if (str == NULL)
		while (nil[i] != '\0')
		{
			count += _putchar(nil[i]);
			i++;
		}	
	while (str[i] != '\0')
	{
		count += _putchar(str[i]);
		i++;
	}
	return (count);
}
