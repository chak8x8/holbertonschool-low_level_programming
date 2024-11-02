#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value from the string.
 */
int _atoi(char *s)
{
int i;
int result = 0;
int sign = 0;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == '-')
{
sign++;
}
else if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');

if (s[i + 1] < '0' || s[i + 1] > '9')
{
break;
}
}
else
{
continue;
}
}

if (sign % 2 != 0)
{
result = -result;
}

return (result);
}
