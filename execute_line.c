#include "monty.h"

/**
 * check_space - checks if line is spaces only
 * @s: string to check
 * Return: 1 or 0
 */

int check_space(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

/**
 * execute2 - execute the operation in the line read
 * @line_number: line number
 * @head: pointer to stack
 * @str: array holding operation
 */

void execute2(unsigned int line_number,
	stack_t **head, char **str)
{
	int found = 0;
	int i = 0;
	instruction_t inst[] = {
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};

	while (inst[i].opcode != NULL)
	{
		if (!strcmp(inst[i].opcode, str[0]))
		{
			found = 1;
			inst[i].f(head, line_number);
		}
		i++;
	}
	if (found == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, str[0]);
		exit(EXIT_FAILURE);
		free_all(str, len_calc(str));
	}
	free_all(str, len_calc(str));
}

/**
 * execute - execute the operation in the line read
 * @line: line read
 * @line_number: line number
 * @head: pointer to stack
 */

void execute(char *line, unsigned int line_number, stack_t **head)
{
	char **str;

	if (check_space(line))
		return;
	str = split_space(line);
	if (str[0][0] == '#')
	{
		free_all(str, len_calc(str));
		return;
	}
	if (!strcmp(str[0], "push"))
	{
		push_op(str, line_number, head);
		return;
	}
	execute2(line_number, head, str);
}
