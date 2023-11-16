#ifndef MONTY_H
#define MONTY_H
#define BUFFER_SIZE 1024
#define OP {\
	{"push", push},\
	{"pall", pall},\
	{"pint", pint},\
	{"pop", pop},\
	{"swap", swap},\
	{"add", add}, \
	{"nop", nop}, \
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct command - Contains info about commands.
 * @buffer: Holds dataread from file.
 * @lines: Array of strings holding tokenized buffer.
 * @args: Contains arguments.
 * @num: Number to push.
 */
typedef struct command
{
	char *buffer;
	char *lines[BUFFER_SIZE];
	char *args[BUFFER_SIZE];
	int num;
} command_t;

extern command_t *cmd;

/* Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **head, const int n);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

void read_file(char *filename);
void tokenize(void);
void extract_commands(char *line);
void execute(void);
char *_strdup(char *s);

#endif /* MONTY_H */
