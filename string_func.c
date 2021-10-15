#include "monty.h"
#include <string.h>
/**
 *_tokenizer_line - item separating function
 *@buffer: string to separate
  *@delimiter: separator
 *Return: pointer to buffer
 */
char **tokenizer(char *buffer, char *delimiter)
{
	char **token = NULL;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	token = malloc(sizeof(char *) * 10);
	if (token == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while ((token[i] = strtok(buffer, delimiter)) != NULL && i < 9)
	{
		i++;
		buffer = NULL;
	}
	return (token);
}
