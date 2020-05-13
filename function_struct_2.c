#include "monty.h"

/**
 * _add - Add the two top elements of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->prev->n = current->prev->n + current->n;
		current->prev->next = NULL;
		free(current);
	}
}

/**
 * _nop - Don't do anything
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	return;
}

/**
 * _sub - Sub the two top elements of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->prev->n = current->prev->n - current->n;
		current->prev->next = NULL;
		free(current);
	}
}

/**
 * _mul - multiply the two top elements of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->prev->n = current->prev->n * current->n;
		current->prev->next = NULL;
		free(current);
	}
}

/**
 * _div - Divide the two top elements of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		if (current->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			code_exit = -1;
			free(current);
			return;
		}
		current->prev->n = current->prev->n / current->n;
		current->prev->next = NULL;
		free(current);
	}
}
