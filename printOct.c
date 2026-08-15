#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * printOctRecursive - Recursive function to print digits in Octadecimal.
 * @n: The unsigned integer to print.
 * Return: The converted octadecimal digits.
 */
int printOctRecursive(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 8)
	{
		count += printOctRecursive(n / 8);
	}

	digit = (n % 8) + '0';
	count += _putchar(digit);

	return (count);
}

/**
 * printOct - Extracts an Octal value from the va_list and passes it through
 * a recursive function.
 * @octList: The argument list.
 * Return: Total number of characters printed in Octadecimal.
 */
int printOct(va_list octList)
{
	unsigned int num = va_arg(octList, unsigned int);

	if (num == 0)
	{
		return (_putchar('0'));
	}

	return (printOctRecursive(num));
}
