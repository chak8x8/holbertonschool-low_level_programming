#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers ordered from min to max.
 * @min: The minimum value in the array.
 * @max: The maximum value in the array.
 *
 * Return: If min > max or malloc fails - NULL.
 * Otherwise - a pointer to the newly created array.
 */
int *array_range(int min, int max)
{
int i = 0, number = 0;
int *array;

if (min > max)
{
return (NULL);
}

number = max - min + 1;

array = malloc(number *sizeof(int));

if (array == NULL)
{
return (NULL);
}

for (i = 0; i < number; i++)
{
array[i] = min + i;
}

return (array);
}
