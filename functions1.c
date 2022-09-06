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
