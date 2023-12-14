#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file (unused). It
 * iterates through the stack starting from the top, printing each character
 * as long as the ASCII value is within the printable character range (1-127).
 * The iteration stops when encountering a non-printable character or reaching
 * the end of the stack.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file (unused).
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}