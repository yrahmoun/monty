#include "monty.h"

/**
 * push_op - execute the push operation
 * @str: array of command
 * @line_number: line number
 * @head: pointer to the stack
 */

void push_op(char **str, unsigned int line_number, stack_t **head)
{
	stack_t *new;

	if (!str[1] || !check_digit(str[1]) || !head)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(str, len_calc(str));
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(str, len_calc(str));
		exit(EXIT_FAILURE);
	}
	new->n = atoi(str[1]);
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
	free_all(str, len_calc(str));
}

/**
 * pall_op - prints elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void pall_op(stack_t **head, unsigned int line_number)
{
	stack_t *curr = *head;
	(void)line_number;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint_op - prints the value at the top of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void pint_op(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_op - removes the top element of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void pop_op(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (!*head || !head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(aux);
}

/**
 * swap_op - swaps the top two elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void swap_op(stack_t **head, unsigned int line_number)
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
	*head = second;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (second->next != NULL)
		second->next->prev = first;
}
