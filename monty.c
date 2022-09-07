#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int line_number = 0;
/**
 * main - program 
 * @argc: argument count
 * @argv: argument list
 * Return: none
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char **tokens = NULL;
	char *buffer = NULL;
	size_t n;
	ssize_t nread;
	FILE *stream;

	if (argc != 2)
		return (usage_error());

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((nread = getline(&buffer, &n, stream)) != -1)
	{
		line_number++;
		tokens = tokenize(buffer);
		if (tokens)
		{
			call(tokens, &head);
			free(tokens);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(stream);

	return (0);
}

/**
 * free_stack - frees memory
 * @stack: pointer to stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
