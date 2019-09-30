#include "monty.h"

/**
 * swap - the opcode swap swaps the top two elements of the stack
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp_next;
	size_t count = 0;
	int num;

	tmp = *stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack && count >= 2)
	{
		tmp = *stack;
		tmp_next = (*stack)->next;
		num = tmp->n;
		tmp->n = tmp_next->n;
		tmp_next->n = num;
	}
}
/**
 * pint - print the first element of a singly linked list (stack)
 * @stack: address to pointer to top of the stack
 * @line_number: line_number, voided argument
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * nop - no operation
 * @stack: address to pointer to head of stack
 * @line_number: line number of current opcode instructions
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
