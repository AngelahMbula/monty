#include "monty.h"
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
	FILE fp;

	if (argc != 2)
		return (usage_error());

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		return (f_open_error(filename));

	while ((getline(&buffer, &n, fp)) != -1)
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
	fclose(fp);

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
