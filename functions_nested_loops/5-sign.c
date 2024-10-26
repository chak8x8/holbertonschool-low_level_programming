#include "main.h"

/**
 * print_sign - prints the sign of a number
 * @n: the number to check
 *
 * Description: Prints '+' if n is greater than zero, '0' if n is zero,
 * and '-' if n is less than zero. Returns 1, 0, or -1 respectively.
 *
 * Return: 1 if n > 0, 0 if n == 0, -1 if n < 0.
 */
int print_sign(int n)
{
if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
_putchar('0');
return (0);
}
else
{
_putchar('-');
return (-1);
}
}
