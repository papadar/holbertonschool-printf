#include <stdarg.h>
#include "main.h"

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
