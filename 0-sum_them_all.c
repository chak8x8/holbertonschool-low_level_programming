#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its parameters
 * @n: The number of parameters
 *
 * Return: The sum of all parameters, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
va_list args;
unsigned int i;
int num, sum = 0;

if (n == 0)
{
return (0);
}

va_start(args, n);

for (i = 0; i < n; i++)
{
num = va_arg(args, int);
sum += num;
}

va_end(args);

return (sum);
}
