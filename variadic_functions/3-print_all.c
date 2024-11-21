#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Prints a character.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_char(va_list args)
{
char c = va_arg(args, int);
printf("%c", c);
}

/**
 * print_int - Prints an integer.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_int(va_list args)
{
int n = va_arg(args, int);
printf("%d", n);
}

/**
 * print_float - Prints a float.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_float(va_list args)
{
double f = va_arg(args, double);
printf("%f", f);
}

/**
 * print_string - Prints a string.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_string(va_list args)
{
char *s = va_arg(args, char*);
if (s == NULL)
{
printf("(nil)");
}
else
{
printf("%s", s);
}
}

/**
 * print_all - Prints anything based on the format.
 * @format: Format string containing the types of arguments passed.
 */
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0;
int printed = 0;

va_start(args, format);

while (format && format[i] != '\0')
{
if (printed)
{
printf(", ");
}
switch (format[i])
{
case 'c':
print_char(args);
printed = 1;
break;

case 'i':
print_int(args);
printed = 1;
break;

case 'f':
print_float(args);
printed = 1;
break;

case 's':
print_string(args);
printed = 1;
break;

default:
break;
}
i++;
}

va_end(args);
printf("\n");
}
