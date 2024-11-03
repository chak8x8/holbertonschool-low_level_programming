#include "main.h"

/**
 * print_number - Helper function to print an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
int j;
int digit[10];
int count = 0;
if (n < 0)
{
_putchar('-');
n = -n;
}

if (n == 0)
{
_putchar('0');
return;
}

while (n > 0)
{
digit[count] = n % 10;
n = n / 10;
count++;
}
for (j = count - 1; j >= 0; j--)
{
_putchar(digit[j] + '0');
}
}

/**
 * print_array - Prints n elements of an array of integers.
 * @a: Pointer to the array of integers.
 * @n: The number of elements to be printed.
 *
 * The numbers are printed in the same order as they are stored
 * in the array, separated by a comma and a space.
 */
void print_array(int *a, int n)
{
int i = 0;
for (i = 0; i < n; i++)
{
print_number(a[i]);
if (i != (n - 1))
{
_putchar(',');
_putchar(' ');
}
}
_putchar('\n');
}
