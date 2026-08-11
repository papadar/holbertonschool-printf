#ifndef MYDEFINE_H
#define MYDEFINE_H

#include <stdarg.h>

typedef struct op
{
        char *op;
        int (*f)(int n, va_list argList);
} op_t;

int printChar(int n, va_list charList);
int printInt(int n, va_list intList);
int printFlot(int n, va_list flotList);
int printStr(int n, va_list strList);
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_op_func(const char *s))(int n, va_list argList);

#endif
