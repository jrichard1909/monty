#define  _GNU_SOURCE
#include "monty.h"


/**
 * main - Monty
 * @argc: argument count
 * @argv: arguments
 * Return: 0 if passed
 */

int main(int argc, char **argv)
{
	vars_t var = {0, NULL, NULL, NULL};
	size_t len;
	stack_t *head = NULL;
	void (*getf)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	var.file_p = fopen(argv[1], "r");
	if (!var.file_p)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(var.line), &len, var.file_p) != -1)
	{
		var.n_line++;
		var.tokens = tokenizer(var.line, " \t\n");
		if (var.tokens[0] == NULL)
		{
			free(var.tokens);
			continue;
		}
		check_if_push(var, head);
		getf = get_op_func(var);
		check_opcode(getf, var, head);
		(*getf)(&head, var.n_line);
		_fail(var, head);
	}
	free(var.line);
	fclose(var.file_p);
	free_stack(head);

	return (0);
}
