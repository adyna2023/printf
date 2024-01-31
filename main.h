#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
        char fmt;
        int (*fn)(va_list, char[], int, int, int, int);
};

int _printf(const char *format, ...);
va_list list, (char buffer[], int flags, int width, int precision, int size);
int handle_print(const char *fmt, int *i,

#endif /* MAIN_H */
