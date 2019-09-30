#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to address of the stack
 * @line_number: number to be assigned to stack element
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *argument;
	int status;

	if (!stack)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clear_stack(stack);
		exit(EXIT_FAILURE);
	}

	argument = strtok(NULL, " ");
	status = isnumber(argument);
	if (status == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		new->n = atoi(argument);
	}

	new->next = *stack;    /* element at the given line number */
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pall - print all elements of stack
 * @stack: address to pointer to top of the stac
 * @line_number: line_number, voided argument
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	for (tmp = *stack; tmp; tmp = tmp->next)
		printf("%d\n", tmp->n);
}
/**
 * clear_stack - clears stack of doubly linked list
 * @h: address of pointer to top of stack
 */
void clear_stack(stack_t **h)
{
	while (*h)
		simple_pop(h);
}

/**
 * pop - the opcode pop removes the top element of the stack
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * simple_pop - the opcode pop removes the top element of the stack
 * @stack: address to pointer to top of the stack
 */
void simple_pop(stack_t **stack)
{
	stack_t *tmp;

	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
