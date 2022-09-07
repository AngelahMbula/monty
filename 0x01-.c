#include "monty.h"
/**
 * usage_err - prints error message when user doesn't give any file or
 * more than one argument to the program
 * Return: always (EXIT_FAILURE)
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints error message if user cannot open file
 * @filename: name of the file
 * Return: (EXIT_FAILURE)
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - prints error message if file contains invalid instruction
 * @line_number: where the instruction appears
 * @opcode: where error occured
 * Return: (EXIT_FAILURE)
 */
int unknown_op_error(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints error message if user can't malloc anymore
 * Return: (EXIT_FAILURE)
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints error message
 * @line_number: where instruction appears
 * Return: (EXIT_FAILURE)
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
