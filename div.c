#include "monty.h"

/**
 * f_div - Divides the second element from the top
 * of the stack by the top element.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * stack has at least two elements. If not, it prints an error message to
 * stderr, closes a file (bus_code.file), frees memory, and exits with EXIT_FAILURE
 * If the top element is zero, it prints an error message for division by zero
 * and exits with EXIT_FAILURE. Otherwise, it divides the second element from
 * the top by the top element and replaces the top element with the result.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus_code.file);
		free(bus_code.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus_code.file);
		free(bus_code.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}