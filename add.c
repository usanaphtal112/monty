#include "monty.h"

/**
 * f_add - Adds the top two elements of a stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It adds the top
 * two elements of the stack and replaces the top element with the result.
 * If the stack has less than two elements, it prints an error message to
 * stderr, closes a file (bus.file), frees memory, and exits with EXIT_FAILURE
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}