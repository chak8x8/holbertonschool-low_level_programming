#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog and its associated memory.
 * @d: Pointer to a dog structure
 */
void free_dog(dog_t *d)
{
if (d != NULL)
{
if (d->name != NULL)
{
free(d->name);
}
if (d->owner != NULL)	
{
free(d->owner);
}

free(d);
}
}
