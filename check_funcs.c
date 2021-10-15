#include "monty.h"

int value[2] = {0, 0};
/**
 * check_opcode - function
 * @get_op: get_op
 * @check: check
 * @head: head
 */
void check_opcode(void(*get_op)(), vars_t check, stack_t *head)
{
	if (get_op == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
		       check.n_line, check.tokens[0]);
		free(check.line);
		fclose(check.file_p);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	free(check.tokens);
}

/**
 * _is_number - function
 * @ptr: ptr
 * Return: value
 */
int _is_number(char *ptr)
{
	int i;

	if (ptr == NULL)
		return (0);

	if (ptr != NULL && ptr[0] == '-')
		ptr++;

	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (!isdigit(ptr[i]))
			return (0);
	}
	return (1);
}

/**
 * check_if_push - function
 * @check: check
 * @head: head
 */
void check_if_push(vars_t check, stack_t *head)
{
	if (strcmp(check.tokens[0], "push") == 0)
	{
		if (_is_number(check.tokens[1]))
		{
			value[0] = atoi(check.tokens[1]);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				check.n_line);
			free(check.line);
			fclose(check.file_p);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *  _fail - function
 * @check: check
 * @head: head
 */
void _fail(vars_t check, stack_t *head)
{
	if (value[1] == -1)
	{
		free(check.line);
		fclose(check.file_p);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
