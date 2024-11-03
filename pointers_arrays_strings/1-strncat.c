#include "main.h"

/**
 * _strncat - concatenates two strings with a limit
 * @dest: destination string to append to
 * @src: source string to append from
 * @n: maximum number of bytes to append from src
 *
 * Return: pointer to the resulting dest string
 **/
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int dest_len = 0;

while (dest[dest_len] != '\0')
{
dest_len++;
}

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[dest_len] = src[i];
dest_len++;
}
dest[dest_len] = '\0';
return (dest);
}
