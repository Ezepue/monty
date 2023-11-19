#include "monty.h"

/**
 *empty_line - Adds "#" to empty line so it is treated as comment.
*/
void empty_line(void)
{
	int i = 0, j = 0;
	char *new_buffer = malloc(2048);

	if (!new_buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(cmd->buffer), free(cmd);
		exit(EXIT_FAILURE);
	}
	for (i = 0; cmd->buffer[i] != '\0'; i++)
	{
		if (cmd->buffer[i] == '\n' && cmd->buffer[i + 1] == '\n')
		{
			new_buffer[j] = '\n';
			new_buffer[j + 1] = '#';
			new_buffer[j + 2] = '\n';
			j += 3;
		}
		else
		{
			new_buffer[j] = cmd->buffer[i];
			j++;
		}
	}
	new_buffer[j] = '\0';
	free(cmd->buffer);
	cmd->buffer = new_buffer;
}
