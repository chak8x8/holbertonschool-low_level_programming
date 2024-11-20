/* 3-calc.h */
#ifndef CALC_H
#define CALC_H

/* Define struct op_t */
typedef struct op
{
char *op;  /* operator */
int (*f)(int, int);  /* corresponding function */
} op_t;

/* Operation functions */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

int (*get_op_func(char *s))(int, int);

#endif /* CALC_H */
