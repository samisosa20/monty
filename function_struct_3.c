#include "monty.h"

/**
 * _mod - Divide the two top elements of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		nose.code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		if (current->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			nose.code_exit = -1;
			free(current);
			return;
		}
		current->prev->n = current->prev->n % current->n;
		current->prev->next = NULL;
		free(current);
	}
}
/**
 * _pchar - print in ASCII
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		nose.code_exit = -1;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	if (current->n >= 0 && current->n <= 127)
		printf("%c\n", current->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		nose.code_exit = -1;
	}
}

/**
 * _pstr - Convert all valid elements to characters
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		if (current->n != 0 || (current->n > 1 && current->n <= 127))
		{
			printf("%c", current->n);
		}
		else
		{
			printf("\n");
			nose.code_exit = -1;
			return;
		}
		current = current->prev;
	}
	printf("\n");
}
