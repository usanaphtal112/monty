#include "monty.h"

/**
 * f_push - Pushes an integer onto the stack.
 *
 * This function takes a pointer to the head of a stack and an unsigned
 * integer representing the line number in the source file. It checks if the
 * argument provided is a valid integer. If not, it prints an error message
 * to stderr, closes a file (bus_code.file), frees memory, and exits with
 * EXIT_FAILURE. If the argument is a valid integer, it pushes the integer
 * onto the stack using either the `addnode` or `addqueue` function based
 * on the value of `bus_code.lifi`.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the source file.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus_code.arg)
	{
		if (bus_code.arg[0] == '-')
			j++;
		for (; bus_code.arg[j] != '\0'; j++)
		{
			if (bus_code.arg[j] > 57 || bus_code.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus_code.file);
			free(bus_code.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus_code.file);
		free(bus_code.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus_code.arg);
	if (bus_code.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}