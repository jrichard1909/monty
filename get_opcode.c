#include "monty.h"

/**
 * get_op_func - function searches for a match between opcode and text
 * and returns the corresponding function
 * @line: struct containing line contents and line number
 * @meta: struct containing all allocated memory
 *
 * Return: pointer to the matching function
 */

void (*get_op_func(char **token))(stack_t **, unsigned int line_number)
{
	instruction_t opcodes = {
		{"push","func_push"},
		{"pall","func_pall"},
		{NULL, NULL}
	}

	for (int i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(token[0], opcodes[i].opcode) == 0)
		{
			if (strcmp(token[0], "push") == 0)
			{
				if (!token[1])
				{
					fprintf(stderr, "L<line_number>: usage: push integer", line_number);
					exit(EXIT_FAILURE);
				}
			}

			return (opcodes[i].f);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s>", line_number, token[0]);
	exit(EXIT_FAILURE);
}
