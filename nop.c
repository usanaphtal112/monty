#include "monty.h"

/**
 * f_nop - No-operation function.
 *
 * This function does nothing and serves as a placeholder in the Monty
 * interpreter. It is used to maintain consistency in the function pointer
 * array for Monty instructions.
 *
 * @head: A pointer to the head of the stack (unused).
 * @counter: The line number in the source file (unused).
 */
void f_nop(stack_t **head, unsigned int counter)
{
    /* No Operations*/
	(void) counter;
	(void) head;
}