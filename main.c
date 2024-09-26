#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content = NULL;
    FILE *file;
    size_t size = 1024;  /* Define a fixed buffer size */
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    content = malloc(size * sizeof(char)); /* Allocate memory for the buffer */
    if (!content)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(content, size, file) != NULL)
    {
        bus.content = content;
        counter++;
        execute(content, &stack, counter, file);
    }

    free(content);
    free_stack(stack);
    fclose(file);
    return (0);
}
