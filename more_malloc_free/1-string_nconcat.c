#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - Returns the length of a string
 * @s: input string
 *
 * Return: Length of the string
 */
unsigned int _strlen(char *s)
{
unsigned int strlen = 0;
while (s[strlen] != '\0')
{
strlen++;
}
return (strlen);
}

/**
 * string_nconcat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes from s2 to use
 *
 * Return: Pointer to newly allocated space in memory with concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int i = 0, s1_length = 0, s2_length = 0, s3_length = 0;
char *s3;

s1 = s1 ? s1 : "";
s2 = s2 ? s2 : "";

s1_length = _strlen(s1);
s2_length = _strlen(s2);

s3_length = s1_length + (n >= s2_length ? s2_length : n) + 1;
s3 = malloc(s3_length *sizeof(char));

if (s3 == NULL)
{
return (NULL);
}
else
{
for (i = 0; i < s1_length; i++)
{
s3[i] = s1[i];
}

for (i = 0; i < s3_length - s1_length; i++)
{
s3[s1_length + i] = s2[i];
}

s3[s3_length - 1] = '\0';

return (s3);
}
}
