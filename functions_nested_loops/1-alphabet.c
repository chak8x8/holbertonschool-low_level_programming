#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Description: This function prints all lowercase alphabet letters
 * using _putchar function, followed by a new line.
 *
 * Return: void
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

