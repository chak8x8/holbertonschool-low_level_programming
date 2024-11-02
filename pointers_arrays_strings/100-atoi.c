#include "main.h"
#include <limits.h>

/**
 * count_signs - Counts the number of '-' signs in the string.
 * @s: The string to check.
 * @index: The current index in the string.
 *
 * Return: The count of '-' signs.
 */
int count_signs(char *s, int *index)
{
int sign = 0;

while (s[*index] == '-' || s[*index] == '+')
{
if (s[*index] == '-')
sign++;
(*index)++;
}

return sign;
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value from the string.
 */
int _atoi(char *s)
{
int i = 0;
int result = 0;
int sign;

sign = count_signs(s, &i);

while (s[i] >= '0' && s[i] <= '9')
{
if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && (s[i] - '0') > 7))
{
return (sign % 2 != 0) ? INT_MIN : INT_MAX;
}

result = result * 10 + (s[i] - '0');
i++;
}

return (sign % 2 != 0) ? -result : result;
}
