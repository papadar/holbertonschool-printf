#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * printperc - prints a literal '%'
 * @percList: va_list (unused)
 * Return: the number of characters that were printed
 */

int printPerc(va_list percList)
{
	(void)percList;
	return (_putchar('%'));
}
