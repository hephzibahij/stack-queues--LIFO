#include <stdio.h>
#include <stdlib.h>

/**
 * getstdin - get the stdlin
 *@lineptr: line from the point
 *@file: from the file
 *
 * Return: 0 is success
 */
ssize_t getstdin(char **lineptr, int file)
{
	size_t buffer_size = 0;
	ssize_t bytes_read = getline(lineptr, &buffer_size, stdin);

	if (bytes_read == -1)
	{
		perror("Error reading input");
	}
	return (bytes_read);
}

/**
 * clean_line - clean the list lines
 *@content: from the content file
 * Return: 0
 */
char *clean_line(char *content)
{
	char *cleaned_content = strdup(content);
	char *end = content + strlen(content) - 1;

	while (isspace(*content))
	{
		content++;
	}
	while (end > content && isspace(*end))
	{
		end--;
	}
	*(end + 1) = '\0';
	if (cleaned_content == NULL)
	{
		perror("Error cleaning line");
		exit(EXIT_FAILURE);
	}
	return (cleaned_content);
}

/**
 * push - push the header file
 *@stack: stack from the files
 *@number: in the number
 */
void push(Node **stack, unsigned int number)
{
	Node *new_node = malloc(sizeof(Node));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pop - pop functions
 *@stack: stack functions
 *@counter: count the numbers
 */
void pop(Node **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}
	Node *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

void swap(Node **stack, unsigned int counter)
{
	int temp = (*stack)->data;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}

void add(Node **stack, int counter)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->data += (*stack)->data;
	pop(stack, counter);
}

/**
 * nop - in the node functions
 *@stack: stack from the files
 *@counter: count the files
 */
void nop(Node **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;
}
