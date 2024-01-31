#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_Buffer(char buffer[], int *buff_Ind);
int get_Flags(const char *format);
int get_Width(const char *format, va_list args);
int get_Precision(const char *format, va_list args);
int get_Size(const char *format);
int handle_Print(const char *fmt, va_list args, char buffer[], int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size);
unsigned long int convert_size_number(long int n, int size);

#endif /* MAIN_H */
