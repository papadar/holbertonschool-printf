#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct op - the struct containing the function pointers
 *
 * @op: the operation character to compare
 * @f: the function pointer to return
 */

typedef struct op
{
	char op;
	int (*f)(va_list argList);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_op_func(const char *s))(va_list argList);
int printIntRecursive(unsigned int n);
int printUSInt(va_list usintList);
int printInt(va_list intList);
int ptintOctRecursive(unsigned int n);
int printOct(va_list octList);
int printHexRecursive(unsigned int n);
int printHex(va_list hexList);
int printStr(va_list strList);
int printChar(va_list charList);

#endif
