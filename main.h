#ifndef MYDEFINE_H
#define MYDEFINE_H

void printChar(va_list charList);
void printInt(va_list intList);
void printFlot(va_list flotList);
void printStr(va_list strList);
int _putchar(char c);
int _printf(const char *format, ...);

typedef struct op
{
	char *op;
	int *f(va_list, argList);
} op_t;

#endif
