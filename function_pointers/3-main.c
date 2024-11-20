#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments
 *
 * Return: 0 on success, or the appropriate error code
 */
int main(int argc, char *argv[])
{
int num1, num2, result;

if (argc != 4)
{
printf("%s\n", "Error");
return (98);
}

num1 = atoi(argv[1]);
num2 = atoi(argv[3]);

if (get_op_func(argv[2]) == NULL)
{
printf("%s\n", "Error");
return (99);
}
else if ((strcmp(argv[2], "%") == 0 || strcmp(argv[2], "/") == 0) && num2 == 0)
{
printf("%s\n", "Error");
return (100);
}
else
{
result = get_op_func(argv[2])(num1, num2);
printf("%d\n", result);
return (0);
}
}
