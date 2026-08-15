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
