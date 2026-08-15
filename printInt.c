#include <stdarg.h>
#include "main.h"

/**
 * printInt - Extracts a +/- int from the va_list prints each digit
 * @intList: The argument list.
 * Return: Total number of characters printed (with minus sign if negative).
 */
int printInt(va_list intList)
{
	int count = 0;
	int num = va_arg(intList, int);
	unsigned int abs_num;

	if (num < 0)
	{
		_putchar('-');
		count++;
		abs_num = (unsigned int)(-num);
	}
	else
	{
		abs_num = (unsigned int)(num);
	}

	count += printIntRecursive(abs_num);
	return (count);
}
