#include "monty.h"

/**
 * add_op - adds the top two elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void add_op(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!*head || !head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	second->n += first->n;
	*head = second;
	(*head)->prev = NULL;
	free(first);
}
