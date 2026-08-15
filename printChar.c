#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * printChar - sends a character to standard output & returns a count
 * @charList: the valist of arguments
 * Return: a count of the total characters printed
 * this should always be 1
 */

int printChar(va_list charList)
{
	int count = 0;
	char car = (char)va_arg(charList, int);

	count = _putchar(car);
	return (count);
}
