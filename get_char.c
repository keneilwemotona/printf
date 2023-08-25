#include "main.h"

/**
* print_char - prints a single character.
* @args: a list of arguments.
* @flags: active flags.
* @width: the width of character.
* @prec: the precision specification.
* @size: specifier size.
* @buffer: array to handle print.
*
* Return: Number of characters printed.
*/

int print_char(va_list args, char buffer[], int flags,
		int width, int prec, int size)
{
	char c  = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, prec, size));
}
