#include "3-calc.h"
#include <string.h>

int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};

int i = 0;
int result = 0;
int ops_size = sizeof(ops) / sizeof(ops[0]);

while (i < ops_size)
{
result = strcmp(s, ops[i].op);
if (result == 0)
{
return (ops[i].f);
}
i++;
}
return (NULL);
}
