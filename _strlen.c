#include "main.h"
/**
* _strlen - print length of  given string.
* @s: string to check.
* Return: integer.
*/

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
