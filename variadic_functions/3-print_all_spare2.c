#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a char.
 * @args: List of arguments.
 */
void print_char(va_list args)
{
char c;
c = va_arg(args, int);
printf("%c", c);
}

/**
 * print_int - Prints an integer.
 * @args: List of arguments.
 */
void print_int(va_list args)
{
int i;
i = va_arg(args, int);
printf("%d", i);
}

/**
 * print_float - Prints a float.
 * @args: List of arguments.
 */
void print_float(va_list args)
{
float f;
f = va_arg(args, double);
printf("%f", f);
}

/**
 * print_string - Prints a string.
 * @args: List of arguments.
 */
void print_string(va_list args)
{
char *str;
str = va_arg(args, char *);

if (str == NULL)
{
printf("(nil)");
return;
}

printf("%s", str);

}

/**
 * handle_case - Handles printing based on format specifier
 * @format: Format specifier (c, i, f, s)
 * @args: Argument list
 * @separator: Pointer to the separator string to manage formatting
 *
 * Description: Depending on the format specifier provided,
 * this function retrieves the corresponding argument from the
 * variadic argument list and prints it, updating the separator
 * string as needed.
 */
void handle_case(char format, va_list args, char **separator)
{
switch (format)
{
case 'c':
printf("%s", *separator);
print_char(args);
*separator = ", ";
break;

case 'i':
printf("%s", *separator);
print_int(args);
*separator = ", ";
break;

case 'f':
printf("%s", *separator);
print_float(args);
*separator = ", ";
break;

case 's':
printf("%s", *separator);
print_string(args);
*separator = ", ";
break;

default:
break;
}
}

/**
 * print_all - Prints arguments based on a format string
 * @format: A list of types of arguments passed to the function
 *
 * Description: This function prints arguments of various types
 * (char, int, float, string) specified in the format string.
 * If the format string is NULL, it prints a new line. The function
 * uses a helper function to handle individual format cases and
 * manages separators between the arguments.
 */
void print_all(const char * const format, ...)
{
unsigned int j = 0;
char *separator = "";
va_list args;

if (format == NULL)
{
printf("\n");
return;
}

va_start(args, format);
while (format[j] != '\0')
{
handle_case(format[j], args, &separator);
j++;
}
va_end(args);
printf("\n");
}

