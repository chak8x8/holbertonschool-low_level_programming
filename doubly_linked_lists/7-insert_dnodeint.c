#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Double pointer to the head of the list
 * @idx: Index to insert the new node at (starts at 0)
 * @n: Data (n) of the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *node;
	unsigned int i = 0;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;

	if (idx == 0)
		return (add_dnodeint(h, n));

	if (*h == NULL)
		return (NULL);

	current = *h;
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL || (current->next == NULL && i < idx - 1))
		free(node);
		return (NULL);

	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	node->next = current->next;
	node->prev = current;

	if (current->next != NULL)
		current->next->prev = node;

	current->next = node;


	return (node);
}
