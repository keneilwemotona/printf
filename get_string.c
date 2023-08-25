#include "main.h"

/**
* print_string - prints a string
* @args: a list of arguments.
* @flags: active flags.
* @width: the width of character.
* @prec: the precision specification.
* @size: specifier size.
* @buffer: array to handle print.
*
* Return: Number of characters printed.
*/

int print_string(va_list args, char buffer[], int flags,
		int width, int prec, int size)
{
	int len = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (prec >= 0 && prec < len)
		len = prec;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, "", 1);
			return (width);
		}

		for (i = width - len; i > 0; i--)
			write(1, "", 1);
		write(1, &str[0], len);
		return (width);
	}

	return (write(1, str, len));
}
