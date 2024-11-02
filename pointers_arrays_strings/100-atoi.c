#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value from the string.
 */
int _atoi(char *s)
{
int i, result = 0, sign = 0;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == '-')
sign++;
else if (s[i] >= '0' && s[i] <= '9')
{
if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && (s[i] - '0') > 7))
return (sign % 2 != 0 ? INT_MIN : INT_MAX);

result = result * 10 + (s[i] - '0');

if (s[i + 1] < '0' || s[i + 1] > '9')
break;
}
}

return (sign % 2 != 0 ? -result : result);
}
