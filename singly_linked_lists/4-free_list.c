#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the first node of the list.
 *
 * Description: 
 * This function iterates through a linked list of type list_t,
 * freeing the memory allocated for each node, including the string
 * data stored in the node. It ensures that all dynamically
 * allocated memory associated with the list is released.
 */
void free_list(list_t *head)
{
	list_t *current;
	list_t *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
