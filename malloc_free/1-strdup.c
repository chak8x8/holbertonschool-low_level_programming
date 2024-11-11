#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string to a newly allocated memory space
 * @str: the input string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 */
char *_strdup(char *str)
{
int i = 0;
int count = 1;
char *array;

if (str == NULL)
{
return (NULL);
}
else
{
for (i = 0; str[i] != '\0'; i++)
{
count++;
}

array = malloc(count);
if (array == NULL)
{
return (NULL);
}
for (i = 0; i < count; i++)
{
array[i] = str[i];
}
array[count] = '\0';
return (array);
}
}
