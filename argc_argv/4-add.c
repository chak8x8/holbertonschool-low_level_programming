#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 if an error occurs
 */
int main(int argc, char *argv[])
{
int i, j, num, result;
if (argc == 1)
{
printf("%d\n", 0);
return (0);
}
else
{
for (i = 1; i < argc; i++)
{
for (j = 0; argv[i][j] != '\0'; j++)
{
if (!isdigit(argv[i][j]))
{
printf("%s\n", "Error");
return (1);
}
}
num = atoi(argv[i]);
result += num;
}
printf("%d\n", result);
return (0);
}
}
