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
	stack_t *new = NULL;
	stack_t *temp = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		nose.code_exit = -1;
		return (NULL);
	}

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
		new->next = NULL;
	}
	return (new);
}

/**
* detect_alpha - detects a character different number
* @string: the string that the user enter
* Return: 0 is fail and 1 is success
*/

int detect_alpha(char *string)
{
	int i = 0;

	if (string == NULL)
		return (1);
	if (string[i] == '-')
		i++;
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
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * list_len - function that returns the number of
 * elements in a linked stack_t list
 * @h: struct
 * Return: Nro elements.
 */
size_t list_len(stack_t **h)
{
	int count = 0;
	stack_t *aux;

	aux = *h;
	if (aux == NULL)
		return (0);

	while (aux != NULL)
	{
		aux = aux->next;
		count++;
	}

	return (count);
}
