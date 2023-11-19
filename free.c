#include "monty.h"

/**
 *free_stack - Frees stack.
 *@stack: Stack to free.
 *
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 *free_all - frees all allocated memory.
 *@stack: Pointer to stack head.
 *
*/
void free_all(stack_t **stack)
{
	int i = 0;

	free_stack(stack);

	free_args();

	for (i = 0; cmd->lines[i] != NULL; i++)
		free(cmd->lines[i]);

	free(cmd->buffer), free(cmd);
}

/**
 *free_args - Frees args.
*/
void free_args(void)
{
	int i;

	for (i = 0; cmd->args[i] != NULL; i++)
		free(cmd->args[i]);
}
