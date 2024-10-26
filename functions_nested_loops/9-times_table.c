#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
int x;
int y;
int product;
for (x = 0; x < 10; x++)
{
for (y = 0; y < 10; y++)
{
product = x * y;
if (product < 10)
{
if (y != 0)
{
_putchar(' ');
}
_putchar(product + '0');
}
else
{
_putchar((product / 10) + '0');
_putchar((product % 10) + '0');
}
if (y < 9)
{
_putchar(',');
_putchar(' ');
}
}
_putchar('\n');
}
}
