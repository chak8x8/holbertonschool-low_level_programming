#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number for which the square root is to be found
 *
 * Return: the square root of n if it exists, -1 otherwise
 */
int _sqrt_recursion(int n)
{
return (_sqrt_helper(n, 1));
}

/**
 * _sqrt_helper - helper function to calculate square root recursively
 * @n: the number to find the square root of
 * @i: the current guess for the square root
 *
 * Return: the square root of n if it exists, -1 otherwise
 */
int _sqrt_helper(int n, int i)
{
if (n < 0)
{
return (-1);
}
else if ((i * i) == n)
{
return (i);
}
else if ((i * i) > n)
{
return (-1);
}
else
{
return (_sqrt_helper(n, i + 1));
}
}
