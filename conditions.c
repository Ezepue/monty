#include "monty.h"

/**
 * condition - Handles push condition.
 * @stack: Stack head pointer.
 * @line_num: Line number.
*/
void condition(stack_t *stack, unsigned long int line_num)
{
	char *endptr;
	int num = 0;

	if (strcmp(cmd->args[0], "push") == 0)
	{
		if (cmd->args[1] == NULL)
		{
			fprintf(stderr, "L%ld: usage: push integer\n", line_num);
			free_all(&stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			num = strtol(cmd->args[1], &endptr, 10);
			if (*endptr != '\0')
			{
				fprintf(stderr, "L%ld: usage: push integer\n", line_num);
				free_all(&stack);
				exit(EXIT_FAILURE);
			}
			cmd->num = num;
		}
	}
}
