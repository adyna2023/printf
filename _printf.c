#include "main.h"

void print_Buffer(char buffer[], int *buff_Ind);

/**
 * _printf - to print a function
 * @format: contains format specifiers
 * Return: Returns number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_Chars = 0, flags, width, precision, size;
	int buff_Ind = 0, printed;
	char buffer[BUFSIZ];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	do {
		if (*format != '%')
		{
			buffer[buff_Ind++] = *format;
			if (buff_Ind == BUFSIZ)
				print_Buffer(buffer, &buff_Ind);
			printed_Chars++;
		} else
		{
			print_Buffer(buffer, &buff_Ind);
			flags = get_Flags(format);
			width = get_Width(format, args);
			precision = get_Precision(format, args);
			size = get_Size(format);
			format++;
			printed = handle_Print(format, args, buffer, flags, width, precision, size);
			if (printed == -1)
			{
				va_end(args);
				return (-1);
			}
			printed_Chars += printed;
		}
	} while (*format++);

	print_Buffer(buffer, &buff_Ind);

	va_end(args);

	return (printed_Chars);
}

/**
 * print_Buffer - to prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_Ind: Index at which to add the next char, represents the length.
 */
void print_Buffer(char buffer[], int *buff_Ind)
{
	if (*buff_Ind > 0)
	{
		write(1, buffer, *buff_Ind);
		*buff_Ind = 0;
	}
}
