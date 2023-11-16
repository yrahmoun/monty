#include "monty.h"

/**
 * check_digit - checks if the string is made of numbers only
 * @s: string to check
 * Return: 1 or 0
 */

int check_digit(char *s)
{
	int i = 0;

	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		return (0);
	while (s[i])
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
