#include "monty.h"

/**
 * mod_op - rest of division the top two elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void mod_op(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!*head || !head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n %= first->n;
	*head = second;
	(*head)->prev = NULL;
	free(first);
}
