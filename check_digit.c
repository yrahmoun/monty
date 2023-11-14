#include "monty.h"

/**
 * check_digit - checks if the string is made of numbers only
 * @s: string to check
 * Return: 1 or 0
 */

int check_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[0] == '-')
			i++;
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
