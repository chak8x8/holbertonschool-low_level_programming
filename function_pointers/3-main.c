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
int (*operation)(int, int);
char *op;

if (argc != 4)
{
printf("%s\n", "Error");
return (98);
}

num1 = atoi(argv[1]);
op = argv[2];
num2 = atoi(argv[3]);

operation = get_op_func(op);

if (operation == NULL || op[1] != '\0')
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
result = operation(num1, num2);
printf("%d\n", result);
return (0);
}
}
