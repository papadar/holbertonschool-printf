#include <stdarg.h>
#include "main.h"

/**
 * printHexRecursive - Recursive function to print digits in hexadecimal.
 * @n: The unsigned integer to print.
 * Return: The number of hexadecimal digits printed.
 */
int printHexRecursive(unsigned int n)
{
	int count = 0;
	char digit;
	char *hexDigit = "0123456789ABCDEF";

	if (n / 16)
	{
		count += printHexRecursive(n / 16);
	}

	digit = hexDigit[n % 16];
	count += _putchar(digit);

	return (count);
}

/**
 * printHex - Extracts an int from the va_list and converts to Hex.
 * @hexList: The argument list.
 * Return: Total number of characters in Hexadecimal, otherwise '0'.
 */
int printHex(va_list hexList)
{
	unsigned int num = va_arg(hexList, unsigned int);

	if (num == 0)
	{
		return (_putchar('0'));
	}

	return (printHexRecursive(num));
}
