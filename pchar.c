#include "monty.h"

/**
 * f_pchar - Prints the ASCII character corresponding to the top element of the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * stack is empty. If so, it prints an error message to stderr, closes a file
 * (bus.file), frees memory, and exits with EXIT_FAILURE. If the top element is
 * outside the valid ASCII range, it prints an error message and exits with
 * EXIT_FAILURE. Otherwise, it prints the ASCII character corresponding to the
 * top element of the stack.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}