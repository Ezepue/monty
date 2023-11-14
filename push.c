#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *n = strtok(NULL, "\n\t\r ");
    int num;

    if (n == NULL || _isdigit(n))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(n);
    if (!add_node(stack, num))
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * pall - prints all values on the stack starting from the top.
 * @stack: double pointer to head of stack.
 * @line_number: line number from script file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;

    (void) line_number;

    while (head != NULL)
    {
        printf("%d\n", head->n);
        head = head->next;
    }
}


/**
 * add_node - Adds a new node at the beginning of a stack_t list.
 * @head: The head of the stack.
 * @n: The integer to add to the stack_t list.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
stack_t *add_node(stack_t **head, const int n)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    new->n = n;
    new->prev = NULL;
    new->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = new;
    }

    *head = new;

    return (new);
}

/**
 * pint - prints the value at the top of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number from script file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }
    free(temp);
}

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
