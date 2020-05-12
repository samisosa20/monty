#include "monty.h"

/**
 * add_dnodeint_end - function that adds a new node
 * at the end of a stack_t list.
 * @head: address
 * @n: number to save
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new;
	stack_t *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	new->prev = temp;
	temp->next = new;
	new->next = NULL;
	return (new);
}
/**
* detect_alpa - detects a character different number
* @string: the string that the user enter
* Return: 0 is fail and 1 is success
*/

int detect_alpha(char *string)
{
	int i = 0;

	if (string == NULL)
		return (1);
	while (string[i])
	{
        if (string[i] >= '0' && string[i] <= '9')
            ;
		else
			return (1);
	    i++;
	}
	return (0);
}
/**
 * free_dlistint - function that free a stack_t list.
 * @head: address
 * Return: none
 */
void free_dlistint(stack_t **head)
{
	stack_t *aux;

	aux = *head;
	while (aux != NULL)
	{
		free(aux);
		aux = aux->next;
	}
	free(head);
}
