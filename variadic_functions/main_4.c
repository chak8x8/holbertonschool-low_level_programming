#include <stdio.h>
#include "variadic_functions.h"

int main(void)
{
    print_all("ceis", 'A', 42, 3.14, "Hello");
    print_all("i", 42);
    print_all("f", 3.14);
    print_all("s", "Hello");
    print_all("c", 'Z');
    print_all(NULL);
    print_all("");

    return 0;
}
