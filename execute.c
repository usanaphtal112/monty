#include "monty.h"

/**
 * execute - Executes Monty bytecode instructions.
 *
 * This function takes a string representing a Monty bytecode instruction, a
 * pointer to the head of a stack, an unsigned integer representing the line
 * number in the source file, and a file pointer. It parses the instruction
 * executes the corresponding function from the provided list of operations.
 * If the instruction is not recognized, it prints an error message to stderr,
 * closes the file, frees memory, and exits with EXIT_FAILURE.
 *
 * @content: A string representing a Monty bytecode instruction.
 * @stack: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 * @file: A file pointer to the source file.
 *
 * Return: 0 on success, 1 if the instruction is a comment or empty.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}