#include "monty.h"

/**
 * _push - Push one element to the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _push(stack_t **stack, unsigned int line_number)
{
	int nro = 0;

	if (detect_alpha(global_variable) == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		nro = atoi(global_variable);
		add_dnodeint_end(stack, nro);
	}
}

/**
 * _pall - Print all elements of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * _pint - Print the last element of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		code_exit = -1;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	printf("%d\n", current->n);
}

/**
 * _pop - Del the last element of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stacky\n", line_number);
		code_exit = -1;
		return;
	}

	while (current->next != NULL)
		current = current->next;
	if (!current)
	{
		fprintf(stderr, "L%u: can't pop an empty stacky\n", line_number);
		code_exit = -1;
		return;
	}
	if (current->next)
		current->next->prev = current->prev;
	if (list_len(stack) == 1)
		*stack = current->next;
	else
		current->prev->next = current->next;
	free(current);
	/*if (current->next != NULL)
	{	
		while (current->next != NULL)
			current = current->next;
	}
	current->prev->next = NULL;
	free(current);*/
}

/**
 * _swap - Swap the two top element of the stack
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int aux;

	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		aux = current->prev->n;
		current->prev->n = current->n;
		current->n = aux;
	}
}
