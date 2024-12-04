#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list
 * @head: Pointer to the head of the list
 *
 * Return: None
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *next;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
