#include "main.h"

/**
 * cap_string - Capitalizes all words in a string.
 * @str: The string to be modified.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
int i = 0;
int j;
char separators[] = {' ', '\t', '\n', ',', ';', '.',
	'!', '?', '"', '(', ')', '{', '}'};

if (str[0] >= 'a' && str[0] <= 'z')
{
str[0] = str[0] - 32;
}

while (str[i] != '\0')
{
for (j = 0; separators[j] != '\0'; j++)
{
if (str[i] == separators[j])
{
if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
{
str[i + 1] -= 32;
}
break;
}
}
i++;
}
return (str);
}
