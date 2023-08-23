#include "main.h"
/**
* _printf - print string to the stdout according to a format.
* @format: character string.
* Return: number of characters printed to stdout.
*/

int _printf(const char *format, ...)
{
	int  count_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count_chars++;
		} else
		{
			format++;
			switch (*format)
			{
				case 'c':
					char c = va_arg(args, int);

					write(1, &c, 1);
					count_chars++;
					break;
				case 's':
					char *_str = va_arg(args, char *);
					int len;

					len = _strlen(_str);
					write(1, _str, len);
					count_chars += len;
					break;
				case '%':
					write(1, format, 1);
					count_chars++;
					break;
				case '\0':
					break;
				default:
					continue;
			}
		}
		format++;
	}
	va_end(args);
	return (count_chars);
}
