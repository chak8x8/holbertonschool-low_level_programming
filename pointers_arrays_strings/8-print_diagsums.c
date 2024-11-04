#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the square matrix (as a 1D array)
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
int i = 0, sum = 0;
for (i = 0; i < size; i++)
{
sum += a[i * size + i];
}
printf("%d, ", sum);

sum = 0;
for (i = size - 1; i >= 0; i--)
{
sum += a[i * size + (size - i - 1)];
}
printf("%d\n", sum);
}
