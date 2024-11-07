#include "main.h"

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to be checked
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}

return (prime_number_helper(n, 2));
}

/**
 * prime_number_helper - helper function to check prime recursively
 * @n: the number to check
 * @i: the current divisor to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int prime_number_helper(int n, int i)
{
if (i * i > n)
{
return (1);
}

if (n % i == 0)
{
return (0);
}

return (prime_number_helper(n, i + 1));
}
