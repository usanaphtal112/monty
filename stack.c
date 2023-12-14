#include "monty.h"

/**
 * f_stack - Sets the stack mode to stack (LIFO).
 *
 * This function takes a pointer to the head of a stack and an unsigned integer
 * representing the line number in the source file (unused). It sets the global
 * variable `bus_code.lifi` to 0, indicating that the stack mode is now stack(LIFO)
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file (unused).
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter; /*Unused parameters*/
	bus_code.lifi = 0;
}