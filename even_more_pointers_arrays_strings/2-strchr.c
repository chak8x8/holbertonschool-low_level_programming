#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to locate
 *
 * Return: a pointer to the first occurrence
 * of c in s, or NULL if c is not found.
 */
char *_strchr(char *s, char c)
{
int i = 0;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == c)
{
return (s + i);
}
}
if (s[i] == c)
{
return (s + i);
}
return (NULL);
}
