#include "monty.h"

/**
 * check_number - check is value is a number
 * @s: struct containing line contents and line number
 */

void check_number(char *s)
{
	(void)s;
}

/**
 * free_stack - function that frees a dlistint_t list.
 * @head: head
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
