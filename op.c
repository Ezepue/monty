#include "monty.h"

/**
 * Montysub - subtracts the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void Montysub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = temp;
}

/**
 * Montydiv - divides the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void Montydiv(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n / (*stack)->n;
	/*printf("sum: %d\n", temp);*/
	pop(stack, line_number);
	(*stack)->n = temp;
}

/**
 * Montymod - performs mod the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void Montymod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	/*printf("sum: %d\n", temp);*/
	pop(stack, line_number);
	(*stack)->n = temp;
}

/**
 * Montymul - mutiplies the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void Montymul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = temp;
}
