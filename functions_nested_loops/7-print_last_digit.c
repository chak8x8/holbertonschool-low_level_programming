#include "main.h"

int print_last_digit(int n)
{
int lastDigit;
if (n < 0)
{
n = 0 - n;
}
lastDigit = n % 10;
_putchar('0' + lastDigit);
return (lastDigit);
}
