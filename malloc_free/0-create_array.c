#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars, and initializes it with a specific char.
 * @size: The size of the array to create
 * @c: The character to initialize the array with
 *
 * Return: Pointer to the array, or NULL if it fails or size is 0
 */

char *create_array(unsigned int size, char c)
{
unsigned int i = 0;
if (size == 0)
{
return (NULL);
}
else
{
char *array = malloc(size);
if (array == NULL)
{
return (NULL);
}
else
{
for (i = 0; i < size; i++)
{
array[i] = c;
}
return (array);
}
}
}
