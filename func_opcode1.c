#include "monty.h"
/**
 * func_pall - pull a value to the stack
 * @stack: the head of the stack
 * @line_number: line number where the opcode is located
 */
void func_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void) line_number;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * func_push - pull a value to the stack
 * @head: the head (stack) of the stack
 * @line_number: line number where the opcode is located
 */
void func_push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *new_head = *head;
	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		value[1] = -1;
		return;
	}

	if (new_head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->n = value[0];

		*head = new_node;
		return;
	}
	new_node->n = value[0];
	new_node->next = new_head;
	new_node->prev = NULL;
	new_head->prev = new_node;
	*head = new_node;
}

/**
 * func_pint - prints the value at the top of the stack.
 * @stack: the head of the stack
 * @line_number: line number where the opcode is located
 */
void func_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h != NULL)
	{
		printf("%d\n", h->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		value[1] = -1;
	}
}

/**
 * func_pop - prints the value at the top of the stack.
 * @head: the head (stack) of the stack
 * @line_number: line number where the opcode is located
 */
void func_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		value[1] = -1;
		return;
	}
	temp = *head;
	if (temp->next == NULL)
	{
		free(temp);
		(*head) = NULL;
		return;
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * func_swap - intercambia los dos elementos superiores de la pila.
 * @head: the head (stack) of the stack
 * @line_number: line number where the opcode is located
 */
void func_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp_1, *temp_2;
	int num_value;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		value[1] = -1;
		return;
	}

	temp_1 = *head;
	temp_2 = temp_1->next;
	num_value = temp_1->n;
	temp_1->n = temp_2->n;
	temp_2->n = num_value;
}
