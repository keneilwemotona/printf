#include "main.h"

/**
* print_binary - prints a single character.
* @args: a list of arguments.
* @flags: active flags.
* @width: the width of character.
* @prec: the precision specification.
* @size: specifier size.
* @buffer: array to handle print.
*
* Return: Number of characters printed.
*/

int print_binary(va_list args, char buffer[], int flags,
		int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
