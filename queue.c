#include "monty.h"

/**
 * addqueue - Adds a new node with a given value to the end of a stack.
 *
 * This function takes a pointer to the head of a stack and an integer value.
 * It allocates memory for a new node, assigns the given value to it, and adds
 * the new node to the end of the stack. If memory allocation fails, it prints
 * an error message to stdout.
 *
 * @head: A pointer to the head of the stack.
 * @n: The integer value to be assigned to the new node.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * f_queue - Sets the stack mode to queue (FIFO).
 *
 * This function takes a pointer to the head of a stack and an unsigned integer
 * representing the line number in the source file (unused). It sets the global
 * variable `bus.lifi` to 1, indicating that the stack mode is now queue(FIFO).
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file (unused).
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}