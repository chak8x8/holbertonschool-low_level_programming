#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
int i = 0;
for (i = 97; i <= 122; i++)
{
if (i == 101 || i == 113)
{
continue;
}
putchar(i);
}
putchar('\n');
return (0);
}
