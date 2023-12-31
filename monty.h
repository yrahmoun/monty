#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t *head);
void execute(char *line, unsigned int line_number, stack_t **head);
char **split_space(char *s);
char **free_all(char **str, int i);
int len_calc(char **s);
void push_op(char **str, unsigned int  line_number, stack_t  **head);
void pall_op(stack_t **head, unsigned int line_number);
int check_digit(char *s);
void pint_op(stack_t **head, unsigned int line_number);
void pop_op(stack_t **head, unsigned int line_number);
void swap_op(stack_t **head, unsigned int line_number);
void add_op(stack_t **head, unsigned int line_number);
void nop_op(stack_t **head, unsigned int line_number);
void sub_op(stack_t **head, unsigned int line_number);
void div_op(stack_t **head, unsigned int line_number);
void mul_op(stack_t **head, unsigned int line_number);
void mod_op(stack_t **head, unsigned int line_number);

#endif
