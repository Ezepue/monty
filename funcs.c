#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n + (*stack)->next->n;
	/*printf("sum: %d\n", temp);*/
	pop(stack, line_number);
	(*stack)->n = temp;
}

/**
 * nop - doesn't do anything.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
