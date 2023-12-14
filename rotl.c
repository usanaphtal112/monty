#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file (unused). It
 * rotates the stack to the top, moving the second element to the top.
 * If the stack is empty or has only one element, the function does nothing.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file (unused).
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}