#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip
 * to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int result = 0;
	unsigned int count = 0;

	result = n ^ m;

	while (result !=  0)
	{
		if ((result & 1) == 1)
		{
			count++;
		}
		result = result >> 1;
	}

	return (count);
}
