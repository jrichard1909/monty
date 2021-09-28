#include "monty.h"

int value[] = {0,0}

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

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	var.file_p = fopen(argv[1], "r");
	if (!var.file_p)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	while (getline(&(var.line), &len, var.file_p) != -1)
	{
		var.n_line++;
		var.tokens = tokenizer(var.line, " \t\n");
		if (var.tokens[0] == "\n")
			continue;
		get_opcode(var.tokens, head);
	}

	return (0);
}
