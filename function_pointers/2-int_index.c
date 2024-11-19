#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: Array of integers to search.
 * @size: Number of elements in the array.
 * @cmp: Function pointer to the comparison function.
 *
 * Return: Index of the first element for which cmp doesn't return 0.
 *         -1 if no match is found or if size <= 0 or array/cmp is NULL.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i = 0;

if (array == NULL || size <= 0 || cmp == NULL)
{
return (-1);
}

for (i = 0; i < size; i++)
{
if (cmp(array[i]) == 0)
{
continue;
}
else
{
return (i);
}
}
return (-1);

}
