#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array, using malloc.
 * @nmemb: Number of elements.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to allocated memory initialized to 0,
 *         or NULL if nmemb or size is 0 or malloc fails.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i = 0;
char *array;

if (nmemb == 0 || size == 0)
{
return (NULL);
}

array = malloc(nmemb * size);

if (array == NULL)
{
return (NULL);
}

for (i = 0; i < (nmemb * size); i++)
{
array[i] = 0;
}

return (array);
}
