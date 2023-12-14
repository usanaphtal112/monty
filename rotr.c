#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file (unused). It
 * rotates the stack to the bottom, moving the last element to the top.
 * If the stack is empty or has only one element, the function does nothing.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file (unused).
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}