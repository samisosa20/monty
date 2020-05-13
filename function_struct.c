#include "monty.h"

void _push(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	int nro = 0;

	if (detect_alpha(global_variable) == 1)
	{
		printf("L%d: usage: push integer\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		nro = atoi(global_variable);
		add_dnodeint_end(stack, nro);
	}
	
}

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		code_exit = -1;
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

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		code_exit = -1;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	printf("%d\n", current->n);
}

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		printf("L%d: can't pop an empty stacky\n", line_number);
		code_exit = -1;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	
	current->prev->next = NULL;
	free(current);
}

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int aux;

	if (list_len(stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
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
