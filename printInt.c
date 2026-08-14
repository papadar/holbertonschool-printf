#include <stdarg.h>
#include "main.h"

/**
 * printInt - Extracts an int from the va_list, handles negtive number and prints.
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