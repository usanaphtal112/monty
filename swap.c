#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * stack has at least two elements. If not, it prints an error message to
 * stderr, closes a file (bus_code.file), frees memory, and exits with EXIT_FAILURE
 * Otherwise, it swaps the values of the top two elements in the stack.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus_code.file);
		free(bus_code.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}