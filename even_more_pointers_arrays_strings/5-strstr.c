#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: the string to be searched
 * @needle: the substring to be located
 *
 * Return: a pointer to the first occurrence of the substring needle
 *         in the string haystack, or NULL if needle is not found.
 *         If needle is an empty string, return haystack.
 */
char *_strstr(char *haystack, char *needle)
{
int i = 0, j = 0, k = 0;

if (needle[0] == '\0')
{
return (haystack);
}

for (; haystack[i] != '\0'; i++)
{
k = i;
j = 0;
while (needle[j] != '\0')
{
if (haystack[k] == needle[j])
{
k++;
j++;
continue;
}
else
{
break;
}
}
if (needle[j] == '\0')
{
return (haystack + i);
}
}
return (NULL);

}
