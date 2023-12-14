#include "monty.h"

/**
 * f_pall - Prints all the elements of the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file (unused). It prints
 * all the elements of the stack, starting from the top.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file (unused).
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}