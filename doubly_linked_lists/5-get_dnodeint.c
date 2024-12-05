#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: The index of the node to retrieve, starting from 0.
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	current = head;
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL || (current->next == NULL && i < index))
	{
		return (NULL);
	}

	return (current);
}
