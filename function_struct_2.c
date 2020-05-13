#include "monty.h"

void _add(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
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

void _nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
   return;
}

void _sub(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
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

void _mul(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
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

void _div(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

	if (list_len(stack) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		if (current->n == 0)
		{
			printf("L%d: division by zero\n", line_number);
			code_exit = -1;
			free(current);
			return;
		}
		current->prev->n = current->prev->n / current->n;
        current->prev->next = NULL;
	    free(current);
	}
}
