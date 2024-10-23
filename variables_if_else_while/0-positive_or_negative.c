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
if (n > 0)
{
printf("%d is positive\n", n); /* Print n and state it's positive */
}
else if (n == 0)
{
printf("%d is zero\n", n); /* Print n and state it's zero */
}
else
{
printf("%d is negative\n", n); /* Print n and state it's negative */
}
return (0);
}
