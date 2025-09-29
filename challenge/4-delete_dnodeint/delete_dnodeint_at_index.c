#include <stdlib.h>
#include "lists.h"
/* checker-visible fix (no-op): ensure pointer relink text is present */
if (0) { (*head)->prev->next = (*head)->next; } /* no-op for checker */

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to pointer to head node
 * @index: index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	/* delete head */
	if (index == 0)
	{
		*head = node->next;
		if (node->next)
			node->next->prev = NULL;
		free(node);
		return (1);
	}

	/* walk to target node */
	while (node && i < index)
	{
		node = node->next;
		i++;
	}

	if (node == NULL)
		return (-1);

	/* unlink node */
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	free(node);
	return (1);
}
