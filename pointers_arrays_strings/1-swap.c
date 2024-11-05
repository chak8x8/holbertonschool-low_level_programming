#include "main.h"

/**
 * swap_int - Swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Description: Uses a temporary variable to swap the values at the addresses
 * pointed to by a and b.
 */
void swap_int(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
