#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: The string to be reversed.
 */
void rev_string(char *s)
{
int i;
int length = 0;
char t;
for (i = 0; s[i] != '\0'; i++)
{
length++;
}
for (i = 0; i < length / 2; i++)
{
t = s[i];
s[i] = s[length - i - 1];
s[length - i - 1] = t;
}
}
