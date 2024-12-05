#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index in a doubly
 * linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;


	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}

	current = *head;
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
	{
		return (-1);
	}

	if (current->next != NULL)
		current->prev->next = current->next;
	if (current->prev != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);

}
