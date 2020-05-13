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
