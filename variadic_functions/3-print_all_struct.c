#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a char.
 * @args: List of arguments.
 */
void print_char(va_list args)
{
printf("%c", va_arg(args, int));
}

/**
 * print_int - Prints an integer.
 * @args: List of arguments.
 */
void print_int(va_list args)
{
printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a float.
 * @args: List of arguments.
 */
void print_float(va_list args)
{
printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string.
 * @args: List of arguments.
 */
void print_string(va_list args)
{
char *str = va_arg(args, char *);
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
va_list args;
unsigned int i = 0, j;
char *separator = "";
printer_t func[] = {
{"c", print_char},
{"i", print_int},
{"f", print_float},
{"s", print_string}
};
va_start(args, format);
while (format && format[i])
{
j = 0;
while (j < 4)
{
if (format[i] == *(func[j].symbol))
{
printf("%s", separator);
func[j].print(args);
separator = ", ";
break;
}
j++;
}
i++;
}
va_end(args);
printf("\n");
}

