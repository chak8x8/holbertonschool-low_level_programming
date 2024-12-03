#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list.
 * @h: Pointer to the head of the list.
 *
 * Description: This function traverses a linked list_t list, counting
 *              each node until the end of the list is reached.
 *
 * Return: The total number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
	size_t num = 0;
	const list_t *node = h;

	while (node != NULL)
	{
		num++;
		node = node->next;
	}
	return (num);
}
