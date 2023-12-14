#include "monty.h"

bus_t bus_code = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty bytecode interpreter.
 *
 * This function serves as the entry point for the Monty bytecode interpreter.
 * It reads a Monty bytecode file specified in the command line arguments,
 * processes each line, and executes the corresponding Monty instructions.
 * The interpreter maintains a stack data structure to manipulate values.
 * If there is an issue with the command line arguments, opening the file, or
 * executing instructions, error messages are printed to stderr,
 * and the program exits with EXIT_FAILURE.
 *
 * @argc: The number of command line arguments.
 * @argv: An array of strings representing the command line arguments.
 *
 * Return: 0 on successful execution.
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus_code.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus_code.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
