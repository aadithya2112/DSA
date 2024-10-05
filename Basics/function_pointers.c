#include <stdio.h>

void printHello(int x)
{
    printf("Hello %d\n", x);
}

int main()
{
    void (*func_ptr)(int) = &printHello;
    (*func_ptr)(2);
    return 0;
}