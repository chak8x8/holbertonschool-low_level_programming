#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_dlistint - Sums all the data (n) of a doubly linked list
 * @head: Pointer to the head of the list
 *
 * Return: Sum of all the data (n) in the list, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	if (head == NULL)
	{
		return (0);
	}

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
