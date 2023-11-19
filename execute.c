#include "monty.h"

/**
 * execute - Execute commands from the Monty language
 */

void execute(void)
{
	instruction_t ops[] = OP;
	stack_t *stack = NULL;
	unsigned long int line_num, i, j;

	for (i = 0; cmd->lines[i] != NULL; i++)
	{
		void (*executor)(stack_t **stack, unsigned int line_number) = NULL;

		line_num = i + 1;
		extract_commands(cmd->lines[i]);
		if (cmd->args[0][0] == '#')
		{
			free_args();
			continue;
		}
		condition(stack, line_num);

		for (j = 0; j < (sizeof(ops) / sizeof(ops[0])); j++)
		{
			if (strcmp(cmd->args[0], ops[j].opcode) == 0)
				executor = ops[j].f;
		}
		if (executor != NULL)
			executor(&stack, line_num);
		else
		{
			fprintf(stderr, "L%ld: unknown instruction %s\n", line_num, cmd->args[0]);
			free_all(&stack);
			exit(EXIT_FAILURE);
		}
		free_args();
	}
	free_stack(&stack);
}
