#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
int i;
for (i = 97; i <= 122; i++) /* ASCII values for 'a' to 'z' */
{
_putchar(i);
}
_putchar('\n'); /* Print new line after the alphabet */
}

