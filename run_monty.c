#include "monty.h"
/**
 * _isdigit - checks if digit is between 0 to 9
 * @c: variable
 * Return: 1 on success, 0 otherwise
 */
static instruction_t ops[] = {
	{"push", _push},
	{"pall", _pall},
	{"pop", _pop},
	{"swap", _swap},
	{"pint", _pint},
	{NULL, NULL}
};

int _isdigit(char *c)
{
	char *n = c;

	if (c == NULL)
		return (0);
	if (*n == '-')
		n++;
	for (; *n != '\0'; n++)
	{
		if ((*n < '0' || *n > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * is_valid - checks if token array is valid
 * @token: token to be checked
 * @stack: pointer to the stack
 * Return: void
 */
void is_valid(char **tokens, stack_t **stack)
{
	int idx = 0;

	if (!tokens[1])
	{
		if (*stack)
			free_stack(stack);
		free(tokens);
		no_int_error(line_number);
		return;
	}
	while (tokens[1][idx])
	{
		if (tokens[1][idx] == '-' && idx == 0)
			idx++;
		if (isdigit(tokens[1][idx] == 0))
		{
			if (*stack)
				free_stack(stack);
			free(tokens);
			no_int_error(line_number);
			return;
		}
		idx++;
	}
}

/**
 * call - call appropriate function
 * @token: token to be checked
 * @stack: pointer to the stack
 * Return: void
 */
void call(char **tokens, stack_t **stack)
{
	int idx = 0;

	while (ops[idx].opcode)
	{
		if (tokens[0][0] == '#')
			return;
		if (strcmp(tokens[0], ops[idx].opcode) == 0)
		{
			if (ops[idx].f)
				ops[idx].f(stack, line_number);
			break;
		}
		idx++;
	}
	if (strcmp(tokens[0], "push") == 0)
	{
		is_valid(tokens, stack);
		(*stack)->n = atoi(tokens[1]);
	}
	else if (!(ops[idx].opcode))
	{
		unknown_op_error(line_number, tokens[0]);
		return;
	}
}

/**
 * tokenize - tokenize a given buffer
 * @buffer: string to tokenize
 * Return: an array
 */
char **tokenize(char *buffer)
{
	char *token = NULL;
	char **array;
	int idx = 3;
	char *delim = "\t \r\n";

	token = strtok(buffer, delim);

	if (token == NULL)
		return (NULL);
	array = malloc(sizeof(char**) *3);

	if (array == NULL)
	{
		free(buffer);
		malloc_error();
	}
	while (--idx)
		array[idx - 1] = NULL;
	while (token)
	{
		if (idx < 3)
			array[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	array[2] = NULL;

	return (array);
}
