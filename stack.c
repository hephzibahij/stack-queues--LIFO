#include "monty.h"

/**
 * main - monty code functions
 *@argc: argument numbers
 *@argv: arguments variables
 *
 * Return: 0 is success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (file == NULL)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		bus.content = clean_line(line);
		execute(bus.content, &stack, line_number, file);
		line_number++;
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
