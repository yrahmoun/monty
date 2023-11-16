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
		fprintf(stderr, "L%d: can't add, stack too short\n",
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

/**
 * nop_op - doesn’t do anything
 * @head: pointer to stack
 * @line_number: line number
 */

void nop_op(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * sub_op - subtracts the top two elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void sub_op(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!*head || !head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	second->n -= first->n;
	*head = second;
	(*head)->prev = NULL;
	free(first);
}

/**
 * div_op - divides the top two elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void div_op(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!*head || !head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
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
	second->n /= first->n;
	*head = second;
	(*head)->prev = NULL;
	free(first);
}

/**
 * mul_op - multiplies the top two elements of the stack
 * @head: pointer to stack
 * @line_number: line number
 */

void mul_op(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!*head || !head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
	exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	second->n *= first->n;
	*head = second;
	(*head)->prev = NULL;
	free(first);
}
