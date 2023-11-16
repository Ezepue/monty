#include "monty.h"

/**
 * execute - Execute commands from the Monty language
 */

void execute(void)
{
	instruction_t ops[] = OP;
	void (*executor)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *stack = NULL, *current;
	unsigned long int i, j, k;

	for (i = 0; cmd->lines[i] != NULL; i++)
	{
		/* printf("Line[%d]: %s\n", i, cmd->lines[i]); */
		extract_commands(cmd->lines[i]);
		if (strcmp(cmd->args[0], "push") == 0)
		{
			if (cmd->args[1] == NULL)
			{
				fprintf(stderr, "L%ld: usage: push integer\n", i);
				exit(EXIT_FAILURE);
			}
			else
				cmd->num = atoi(cmd->args[1]);
		}
		for (j = 0; j < (sizeof(ops) / sizeof(ops[0])); j++)
		{
			if (strcmp(cmd->args[0], ops[j].opcode) == 0)
				executor = ops[j].f;
		}
		if (executor != NULL)
			executor(&stack, i);
		else
			printf("%s: Invalid command\n", cmd->args[0]);

		for (k = 0; cmd->args[k] != NULL; k++)
			free(cmd->args[k]);
	}

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
