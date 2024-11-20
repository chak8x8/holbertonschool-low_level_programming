#include "3-calc.h"
#include <stdlib.h>
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


if (s == NULL || *s == '\0')
{
return NULL;
}


while (ops[i].op != NULL)
{
if (strcmp(s, ops[i].op) == 0)
{
return ops[i].f;
}
i++;
}

return NULL;
}
