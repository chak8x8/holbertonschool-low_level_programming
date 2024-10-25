#include "main.h"

/**
 * _isalpha - checks if a character is an alphabetic letter.
 * @c: The character to be checked, represented as an integer.
 *
 * Return: 1 if c is a letter (either uppercase or lowercase),
 *         0 otherwise.
 *
 * Description: This function checks if the given character
 * (provided as an integer) is within the ASCII range for
 * alphabetic characters. It returns 1 if the character is
 * either an uppercase or lowercase letter, and 0 if it is not.
 */
int _isalpha(int c)
{
if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
{
return (1);
}
else
{
return (0);
}
}
