

void func_push(stack_t **head, unsigned int line_number)
{
	stack_t new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	
}



void _pchar(stack_t **head, unsigned int line_number)
{
	int ascii_num;

	if (*top == NULL)
		pchar_error2(line_number);

	ascii_num = (*top)->n;

	if (ascii_num < 0 || ascii_num > 127)
		pchar_error(line_number);
	putchar(ascii_num);
	putchar('\n');
}
