#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The string to be printed between the strings.
 * @n: The number of strings passed to the function.
 *
 * Description: If separator is NULL, it is not printed.
 *              If a string is NULL, "(nil)" is printed instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
char *string;

va_start(args, n);

for (i = 0; i < n; i++)
{
string = va_arg(args, char*);
if (string != NULL)
{
printf("%s", string);
}
else
{
printf("%s", "(nil)");
}
if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}
}

va_end(args);

printf("\n");
}
