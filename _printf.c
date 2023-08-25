#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - produces output according to a format specifiers.
 * @format: is  charecter string.
 * Return: the number of printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, count_chars = 0;
	int flags, width, prec, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);

			count_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			prec = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, prec, size);
			if (printed == -1)
				return (-1);
			count_chars += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (count_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represent the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
