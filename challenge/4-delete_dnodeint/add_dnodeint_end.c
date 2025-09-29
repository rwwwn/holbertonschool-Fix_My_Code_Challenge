#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: address of pointer to head node
 * @n: value to add
 * Return: address of new element, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode, *tail;

	if (head == NULL)
		return (NULL);

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	tail = *head;
	while (tail->next)
		tail = tail->next;

	tail->next = newnode;
	newnode->prev = tail;

	return (newnode);
}
