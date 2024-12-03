#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: String to duplicate and store in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	char *s;
	const char *temp;
	unsigned int length = 0;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		return (NULL);
	}

	s = strdup(str);
	if (s == NULL)
	{
		free(node);
		return (NULL);
	}

	*temp = str;
	while (*temp != '\0')
	{
		length++;
		temp++;
	}

	node->str = s;
	node->len = length;
	node->next = *head;
	*head = node;

	return (node);
}
