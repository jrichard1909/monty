#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct vars_s - variables of the project
 * @n_line: number of line
 * @tokens: double pointer
 * @file_p: pointer to file
 * @line: pointer char
 *
 * Description: variables
 */

typedef struct vars_s
{
	int n_line;
	char **tokens;
	FILE *file_p;
	char *line;
} vars_t;

extern int value[];

void (*f)(stack_t **, unsigned int);

void func_push(stack_t **head, unsigned int line_number);
void func_pall(stack_t **head, unsigned int line_number);
void func_pchar(stack_t **head, unsigned int line_number);

void check_number(char *s);
void check_opcode(void(*get_op)(), vars_t check, stack_t *head);
void check_if_push(vars_t check, stack_t *head);
void _fail(vars_t check, stack_t *head);
int _is_number(char *ptr);
char **tokenizer(char *buffer, char *delimiter);
void free_stack(stack_t *head);

void (*get_op_func(vars_t))(stack_t **, unsigned int);

void func_pint(stack_t **stack, unsigned int line_number);
void func_pop(stack_t **head, unsigned int line_number);
void func_swap(stack_t **head, unsigned int line_number);
void func_add(stack_t **head, unsigned int line_number);
void func_nop(stack_t **head, unsigned int line_number);
void func_sub(stack_t **head, unsigned int line_number);
void func_div(stack_t **head, unsigned int line_number);
void func_mul(stack_t **head, unsigned int line_number);
void func_mod(stack_t **head, unsigned int line_number);
void func_pstr(stack_t **head, unsigned int line_number);
void func_rotl(stack_t **head, unsigned int line_number);
void func_rotr(stack_t **head, unsigned int line_number);

#endif
