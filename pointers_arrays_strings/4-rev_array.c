#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers.
 * @a: The array to be reversed.
 * @n: The number of elements in the array.
 *
 * Return: void (no value returned).
 */
void reverse_array(int *a, int n)
{
int temp = 0;
int i = 0;

for (; i < n / 2; i++)
{
temp = a[i];
a[i] = a[n - 1 - i];
a[n - 1 - i] = temp;
}
}
