#include "main.h"

/**
 * _islower - checks if a character is lowercase.
 * @c: The character to be checked, represented as an integer.
 *
 * Return: 1 if c is lowercase (between 'a' and 'z'),
 *         0 otherwise.
 *
 * Description: This function checks if the given character
 * (provided as an integer) falls within the ASCII range for
 * lowercase letters. It returns 1 if the character is lowercase
 * and 0 if it is not.
 */
int _islower(int c)
{
if (c >= 97 && c <= 122)
{
return (1);
}
else
{
return (0);
}
}
