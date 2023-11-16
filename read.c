#include "monty.h"

/**
 * read_file - Read the content of a file into a buffer
 * @filename: Name of the file to read
 */

void read_file(char *filename)
{
	ssize_t bytesRead = 0, written = 0;
	int file = open(filename, O_RDONLY);

	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	cmd->buffer[0] = '\0';
	while (1)
	{
		bytesRead = read(file, cmd->buffer, 1024);
		written += bytesRead;
		if (bytesRead == 0)
		{
			break;
		}
	}
	cmd->buffer[written] = '\0';
	close(file);
}

/**
 * tokenize - Tokenize the content of cmd->buffer into lines
 */
void tokenize(void)
{
	char *token = NULL;
	int i = 0;

	token = strtok(cmd->buffer, "\n");
	while (token != NULL)
	{
		cmd->lines[i] = _strdup(token);
		token = strtok(NULL, "\n");
		i += 1;
	}
}

/**
 * extract_commands - Extract commands from a line
 * @line: Line containing commands
 */
void extract_commands(char *line)
{
	int i;
	char *token = NULL;

	for (i = 0; i < BUFFER_SIZE; i++)
		cmd->args[i] = NULL;

	token = strtok(line, " ");
	i = 0;
	while (token != NULL && i < 2)
	{
		cmd->args[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
}
