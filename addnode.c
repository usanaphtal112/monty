#include "monty.h"

/**
 * addnode - Adds a new node with a given value to the beginning of a stack.
 *
 * This function takes a pointer to the head of a stack and an integer value.
 * It allocates memory for a new node, assigns the given value to it, and adds
 * the new node to the beginning of the stack. If memory allocation fails, it
 * prints an error message to stdout and exits the program.
 *
 * @head: A pointer to the head of the stack.
 * @n: The integer value to be assigned to the new node.
 */
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}