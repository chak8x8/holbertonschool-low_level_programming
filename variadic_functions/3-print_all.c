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
 * print_all - Prints anything based on the format.
 * @format: Format string containing the types of arguments passed.
 */
void print_all(const char * const format, ...)
{
unsigned int j = 0;
char *separator = "";
va_list args;
int format_length = 0;

va_start(args, format);

while (format[format_length] != '\0')
{
format_length++;
}

while (format != NULL && format[j] != '\0')
{

printf("%s", separator);

switch(format[j])
{
case 'c':
print_char(args);
separator = ", ";
break;

case 'i':
print_int(args);
separator = ", ";
break;

case 'f':
print_float(args);
separator = ", ";
break;

case 's':
print_string(args);
separator = ", ";
break;

default:
separator = "";
break;
}
j++;
}
va_end(args);
printf("\n");
}
