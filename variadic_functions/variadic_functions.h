#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdarg.h>

/**
 * struct printer - Struct to select a print function.
 * @symbol: Format symbol.
 * @print: Corresponding print function.
 */
typedef struct printer
{
    char *symbol;
    void (*print)(va_list args);
} printer_t;

int sum_them_all(const unsigned int n, ...); /* Add this line */

void print_all(const char *const format, ...);
void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_string(va_list args);

#endif /* VARIADIC_FUNCTIONS_H */