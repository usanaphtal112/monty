#include "monty.h"

/**
 * free_stack - Frees a stack and its elements.
 *
 * This function takes a pointer to the head of a stack and frees the entire
 * stack along with its elements. It iterates through the stack, freeing each
 * node, and updates the head to the next node until the entire stack is freed
 *
 * @head: A pointer to the head of the stack.
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}