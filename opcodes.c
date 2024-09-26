#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number where the opcode appears.
 * @arg: The integer to be pushed onto the stack.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int num;

    if (arg == NULL || !is_number(arg))  // Validate if arg is a valid integer
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(arg);  // Convert the argument to an integer
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number where the opcode appears (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;  // Line number is not used in this opcode

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

