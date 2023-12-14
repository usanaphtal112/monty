#include "monty.h"

/**
 * f_pint - Prints the value at the top of the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * stack is empty. If so, it prints an error message to stderr, closes a file
 * (bus_code.file), frees memory, and exits with EXIT_FAILURE. Otherwise, it prints
 * the value at the top of the stack.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus_code.file);
		free(bus_code.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}