#include "monty.h"

/**
 * get_op_func - function searches for a match between opcode and text
 * and returns the corresponding function
 * @var: vars
 *
 * Return: pointer to the matching function
 */

void (*get_op_func(vars_t var))(stack_t **head, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pchar", func_pchar},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{"mod", func_mod},
		{"pstr", func_pstr},
		{"rotl", func_rotl},
		{"rotr", func_rotr},
		{NULL, NULL}
	};

	if (var.tokens[0][0] == '#')
	{
		return (func_nop);
	}
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(var.tokens[0], opcodes[i].opcode) == 0)
		{
			return (*(opcodes[i]).f);
		}
		i++;
	}
	/*free()*/
	return (0);
}
