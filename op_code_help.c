#include "monty.h"

/**
 * add - the opcode add adds the top two elements of the stack
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum, count = 0;
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack && count >= 2)
	{
		tmp = (*stack)->next;
		sum = (*stack)->n + tmp->n;
		tmp->n = sum;
		pop(stack, line_number);
	}
}

/**
 * sub - substracts the top element of the stack
 * from the second top element of the stack.
 * @stack: address to pointer of top of the stack
 * @line_number: line number of monty bytecode file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int value, len = 0;

	for (tmp = *stack; tmp; tmp = tmp->next)
		len++;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		clear_stack(stack);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= value;
}

/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: address to pointer of top of the stack
 * @line_number: line number of monty bytecode file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int value, len = 0;

	for (tmp = *stack; tmp; tmp = tmp->next)
		len++;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		clear_stack(stack);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= value;
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: address to pointer of top of the stack
 * @line_number: line number of monty bytecode file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int value, len = 0;

	for (tmp = *stack; tmp; tmp = tmp->next)
		len++;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		clear_stack(stack);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		clear_stack(stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n /= value;
}
