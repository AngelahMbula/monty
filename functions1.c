#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @stack: head of stack
 * @n: line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int n)
{
	stack_t *new_node = NULL;
	(void) n;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(stack);
		return (malloc_error());
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!(*stack))
		*stack = new_node;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
 * _pall - prints all values on the stack
 * @stack: head of the stack
 * @n: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void) n;

	if (*stack == NULL || stack == NULL)
		return;
	node = *stack;

	while (node)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}

/**
 * _pint - prints value at the top of the stack
 * @stack: stack of list
 * @n: line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int n)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: stack of list
 * @n: line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int n)
{
	stack_t *top = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;

	if (top->next != NULL)
		top->next->prev = top->prev;

	free(top);
}

/**
 * _swap - swaps the top two elements on the stack
 * @stack: stack of list
 * @line_number: line number
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
