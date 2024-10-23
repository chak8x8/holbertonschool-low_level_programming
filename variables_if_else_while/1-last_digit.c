#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

/* betty style doc for function main goes there */
int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
/* your code goes there */
int lastDigit = n % 10;

if (lastDigit > 5) /* Check if the last digit is greater than 5 */
{
printf("Last digit of %d is %d and is greater than 5\n"
		, n, lastDigit); /* Corrected print statement */
}
else if (n == 0) /* Check if the last digit is 0 */
{
printf("Last digit of %d is %d and is greater than 5\n"
		, n, lastDigit); /* Corrected print statement */
}
else
{
printf("Last digit of %d is %d and is less than 6 and not 0"
		, n, lastDigit); /* Corrected print statement */
}
return (0);
}
