#include "monty.h"

/**
 * f_sub - Subtracts the top element of the stack from the second element.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * stack has at least two elements. If not, it prints an error message to
 * stderr, closes a file (bus_code.file), frees memory, and exits with EXIT_FAILURE.
 * Otherwise, it subtracts the top element of the stack from the second element
 * and replaces the top element with the result.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus_code.file);
		free(bus_code.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}