#include "main.h"
#include <stdlib.h>

/**
 * _strlen - calculates the length of a string
 * @s: the input string
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
int length = 0;

while (s[length] != '\0')
{
length++;
}
return (length);
}

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: the first input string
 * @s2: the second input string
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
int i = 0, s1_length, s2_length, total_length;
char *result;

if (s1 == NULL)
{
s1 = "";
}
if (s2 == NULL)
{
s2 = "";
}
s1_length = _strlen(s1);
s2_length = _strlen(s2);
total_length = s1_length + s2_length + 1;

result = malloc(total_length *sizeof(char));
if (result == NULL)
{
return (NULL);
}
for (i = 0; i < s1_length; i++)
{
result[i] = s1[i];
}
for (i = 0; i < s2_length; i++)
{
result[s1_length + i] = s2[i];
}

result[total_length - 1] = '\0';

return (result);
}
