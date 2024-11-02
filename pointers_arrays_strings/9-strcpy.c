#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src, including the null byte,
 *           to the buffer pointed to by dest.
 * @dest: The destination buffer where the string is copied.
 * @src: The source string to copy.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
int i;
int count = 0;
for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
count++;
}
dest[count] = '\0';
return (dest);
}
