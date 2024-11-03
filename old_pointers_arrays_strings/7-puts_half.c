#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: The string to be printed
 */
void puts_half(char *str)
{
int i;
int length = 0;
int n;
for (i = 0; str[i] != '\0'; i++)
{
length++;
}
if (length % 2 != 0)
{
n = (length + 1) / 2;
}
else
{
n = length / 2;
}

for (i = n; i < length; i++)
{
_putchar(str[i]);
}
_putchar('\n');
}
