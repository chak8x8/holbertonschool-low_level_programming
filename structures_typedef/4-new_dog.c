#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if failure.
 */
char *_strdup(char *str)
{
int i = 0, length = 0;
char *str_copy;

if (str == NULL)
{
return (NULL);
}
else
{
for (i = 0; str[i] != '\0'; i++)
{
length++;
}

str_copy = malloc(length + 1);

if (str_copy == NULL)
{
return (NULL);
}
else
{
for (i = 0; i < length; i++)
{
str_copy[i] = str[i];
}
str_copy[length] = '\0';
}

return (str_copy);
}

}

/**
 * new_dog - Creates a new dog.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog, or NULL if failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;

if (name == NULL || owner == NULL)
{
return (NULL);
}

d = malloc(sizeof(dog_t));

if (d == NULL)
{
return (NULL);
}

d->name = _strdup(name);
if (d->name == NULL)
{
free(d);
return (NULL);
}

d->age = age;

d->owner = _strdup(owner);
if (d->owner == NULL)
{
free(d->name);
free(d);
return (NULL);
}

return (d);
}
