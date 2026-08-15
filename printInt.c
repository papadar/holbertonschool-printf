#include <stdarg.h>
#include "main.h"

/**
 * printIntRecursive - Recursive function to print digits.
 * @n: The unsigned integer to print.
 * Return: The number of digits printed.
 */
int printIntRecursive(unsigned int n)
{
	int count = 0;

	if (n / 10)
	{
		count += printIntRecursive(n / 10);
	}

	_putchar('0' + (n % 10));
	return (count + 1);
}

/**
 * printUSInt - Extracts an int from the va_list and prints it.
 * @usintList: The argument list.
 * Return: Total number of characters printed.
 */
int printUSInt(va_list usintList)
{
	int count = 0;
	unsigned int num = va_arg(usintList, unsigned int);

	count += printIntRecursive(num);
	return (count);
}

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
