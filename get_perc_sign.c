#include "main.h"

/**
* print_percent - prints a percent sign.
* @args: a list of arguments.
* @flags: active flags.
* @width: the width of character.
* @prec: the precision specification.
* @size: specifier size.
* @buffer: array to handle print.
*
* Return: Number of characters printed.
*/

int print_percent(va_list args, char buffer[], int flags,
		int width, int prec, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	return (write(1, "%%", 1));
}
