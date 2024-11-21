#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Prints a character.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_char(va_list args, char *separator)
{
printf("%s%c", separator, (char) va_arg(args, int));
}

/**
 * print_int - Prints an integer.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_int(va_list args, char *separator)
{
printf("%s%d", separator, va_arg(args, int));
}

/**
 * print_float - Prints a float.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_float(va_list args, char *separator)
{
printf("%s%f", separator, va_arg(args, double));
}

/**
 * print_string - Prints a string.
 * @args: List of arguments.
 * @separator: Separator to print between values.
 */
void print_string(va_list args, char *separator)
{
char *str;

str = va_arg(args, char *);
if (str == NULL)
{
str = "(nil)";
}
printf("%s%s", separator, str);
}

/**
 * print_all - Prints anything based on the format.
 * @format: Format string containing the types of arguments passed.
 */

void print_all(const char * const format, ...)
{
va_list args;
int i;
char *separator = "";

if (format == NULL)
{
return;
}

va_start(args, format);

while (format[i] != '\0')
{
switch (format[i])
{
case 'c':
print_char(args, separator);
break;

case 'i':
print_int(args, separator);
break;

case 'f':
print_float(args, separator);
break;

case 's':
print_string(args, separator);
break;

default:
i++;
continue;
}
separator = ", ";
i++;
}
va_end(args);
printf("\n");
}
