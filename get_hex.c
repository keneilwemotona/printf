#include "main.h"

/**
* print_hexadecimal - prints an unsigned number in hex.
* @args: a list of arguments.
* @flags: active flags.
* @width: the width of character.
* @prec: the precision specification.
* @size: specifier size.
* @buffer: array to handle print.
*
* Return: Number of characters printed.
*/

int print_hexadecimal(va_list args, char buffer[], int flags,
		int width, int prec, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer, flags,
				'x', width, prec, size));
}
