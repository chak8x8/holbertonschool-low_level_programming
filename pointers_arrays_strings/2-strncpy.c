#include "main.h"

/**
 * _strncpy - Copies a string from src to dest.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to copy from src.
 *
 * Return: A pointer to the resulting dest string.
 */
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

for (i = 0; i < n; i++)
{
if (i < n && src[i] != '\0')
{
dest[i] = src[i];
}
else
{
dest[i] = '\0';
}
}

return (dest);
}
