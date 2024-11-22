#include<stdio.h>
#include<stdarg.h>
/**
 * struct printer - Struct for selecting correct printing function.
 * @symbol: Format symbol (e.g., "c", "i", "f", "s").
 * @print: Pointer to the corresponding print function.
 */
typedef struct printer
{
char *symbol;
void (*print)(va_list args);
} printer_t;
/**
 * print_char - Prints a character.
 * @args: Argument list containing the character to print.
 */
void print_char(va_list args)
{
char c = va_arg(args, int);
printf("%c", c);
}
/**
 * print_int - Prints an integer.
 * @args: Argument list containing the integer to print.
 */
void print_int(va_list args)
{
int n = va_arg(args, int);
printf("%d", n);
}
/**
 * print_float - Prints a float.
 * @args: Argument list containing the float to print.
 */
void print_float(va_list args)
{
double f = va_arg(args, double);
printf("%f", f);
}
/**
 * print_string - Prints a string.
 * @args: Argument list containing the string to print.
 */
void print_string(va_list args)
{
char *s = va_arg(args, char *);
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
unsigned int i = 0, j;
char *separator = "";
printer_t func[] = {
{"c", print_char},
{"i", print_int},
{"f", print_float},
{"s", print_string}
};
va_start(args, format);
while (format != NULL && format[i] != '\0')
{
j = 0;
while (j < 4 && *(format + i) != *(func[j].symbol))
j++;
if (j < 4)
{
printf("%s", separator);
func[j].print(args);
separator = ", ";
}
i++;
}
va_end(args);
printf("\n");
}

