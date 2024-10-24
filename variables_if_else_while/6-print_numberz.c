#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i = 0;  // Using int, not char
    for (i = 48; i <= 57; i++)  // ASCII values for digits 0-9
    {
        putchar(i);  // Print each digit
    }
    putchar('\n');  // Print new line
    return (0);
}
