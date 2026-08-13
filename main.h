#ifndef MYDEFINE_H
#define MYDEFINE_H

#include <stdarg.h>

typedef struct op
{
        char *op;
        int (*f)(va_list argList);
} op_t;

int printChar(va_list charList);
int printInt(va_list intList);
int printFlot(va_list flotList);
int printStr(va_list strList);
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_op_func(char s))(va_list argList);

#endif
