#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
extern unsigned int line_number;

/**
 *
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *
 *   * @n: integer
 *
 *    * @prev: points to the previous element of the stack (or queue)
 *
 *     * @next: points to the next element of the stack (or queue)
 *
 *      *
 *
 *       * Description: doubly linked list node structure
 *
 *        * for stack, queues, LIFO, FIFO
 *
 *         */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 *
 *  * struct instruction_s - opcode and its function
 *
 *   * @opcode: the opcode
 *
 *    * @f: function to handle the opcode
 *
 *     *
 *
 *      * Description: opcode and its function
 *
 *       * for stack, queues, LIFO, FIFO
 *
 *        */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int usage_error(void);
int f_open_error(char *filename);
int unknown_op_error(unsigned int line_number, char *opcode);
int malloc_error(void);

void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int n);
void _pint(stack_t **stack, unsigned int n);
void _pop(stack_t **stack, unsigned int n);
void _swap(stack_t **stack, unsigned int line_number);
int _isdigit(char *c);
void is_valid(char **tokens, stack_t **stack);
void call(char **tokens, stack_t **stack);
char **tokenize(char *buffer);
void free_stack(stack_t **stack);
int no_int_error(unsigned int line_number);
size_t getline(char **string, size_t *n, FILE *stream);

#endif
