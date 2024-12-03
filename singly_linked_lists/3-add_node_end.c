#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A pointer to the pointer to the first node of the list.
 * @str: The string to be duplicated and stored in the new node.
 *
 * Description: This function creates a new node, duplicates the string 
 * @str, and adds the node at the end of the list. The new node's 
 * `next` pointer will be set to `NULL`. If memory allocation fails, 
 * the function returns `NULL`. If the node is successfully added, 
 * the function returns the address of the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node;
	char *s = strdup(str);;
	const char *temp = str;
	unsigned int length = 0;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		return (NULL);
	}

	if (s == NULL)
	{
		free(node);
		return (NULL);
	}

	while(*temp != '\0')
	{
		length++;
		temp++;
	}

	node->str = s;
	node->len = length;

	while (*head != NULL && (*head)->next != NULL)
	{
		head = &(*head)->next;
	}
	(*head)->next = node;

}
