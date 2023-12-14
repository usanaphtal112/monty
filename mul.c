#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * stack has at least two elements. If not, it prints an error message to
 * stderr, closes a file (bus.file), frees memory, and exits with EXIT_FAILURE
 * Otherwise, it multiplies the top two elements of the stack and replaces the
 * top element with the result.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}