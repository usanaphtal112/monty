#include "monty.h"

/**
 * f_push - Pushes an integer onto the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * argument provided is a valid integer. If not, it prints an error message
 * to stderr, closes a file (bus.file), frees memory, and exits with
 * EXIT_FAILURE. If the argument is a valid integer, it pushes the integer
 * onto the stack using either the `addnode` or `addqueue` function based
 * on the value of `bus.lifi`.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}