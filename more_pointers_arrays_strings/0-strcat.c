#include "main.h"
/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string to which src will be appended.
 * @src: Source string to append to dest.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int dest_len = 0;
while (dest[dest_len] != '\0')
{
dest_len++;
}
while (src[i] != '\0')
{
dest[dest_len] = src[i];
dest_len++;
i++;
}
dest[dest_len] = '\0';
return (dest);
}
