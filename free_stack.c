#include "monty.h"

/**
 * free_stack - frees the linked list representing the stack
 * @head: pointer to list
 */

void free_stack(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
