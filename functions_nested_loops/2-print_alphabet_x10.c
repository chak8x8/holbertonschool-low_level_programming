#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase ten times
 *
 * Description: This function prints all lowercase alphabet letters
 * using _putchar function, followed by a new line.
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
int i;
int count = 0;

do {
for (i = 'a'; i <= 'z'; i++)
{
_putchar(i);
}
_putchar('\n');
count++;
} while (count < 10);
}

