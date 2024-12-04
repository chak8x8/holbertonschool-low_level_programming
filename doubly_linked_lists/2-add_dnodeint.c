#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Double pointer to the head of the list.
 * @n: The value to store in the new node.
 *
 * Return: Address of the new node, or NULL if it fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;
	
	if (head == NULL)
	{
		return (NULL);
	}

	node = malloc(sizeof(dlistint_t));
	if (node = NULL)
	{
		free(node);
		return (NULL);
	}

	node->n = n;
	node->prev = NULL;
	node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = node;
	}

	*head = node;


	return (node);
}
