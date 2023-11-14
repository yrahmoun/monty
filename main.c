#include "monty.h"

/**
 * main - main function
 * @ac: number of arguments
 * @av: arguments:
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int ac, char **av)
{
	FILE *file;
	size_t bufsize = 1024;
	stack_t *head = NULL;
	char *line = NULL;
	int line_number = 0;
	int line_read;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_read = getline(&line, &bufsize, file)) != -1)
	{
		line_number++;
		execute(line, line_number, &head);
	}
	free_stack(head);
	if (line)
		free(line);
	fclose(file);
	return (0);
}
