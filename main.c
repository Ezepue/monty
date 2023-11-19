#include "monty.h"

command_t *cmd = NULL;

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i = 0;
	char *filename = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	cmd = malloc(sizeof(command_t));
	if (!cmd)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cmd->buffer = malloc(1024);
	if (!cmd->buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(cmd);
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	read_file(filename);
	empty_line();
	tokenize();
	execute();

	for (i = 0; cmd->lines[i] != NULL; i++)
		free(cmd->lines[i]);
	free(cmd->buffer), free(cmd);
	return (0);
}
