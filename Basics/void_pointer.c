#include <stdio.h>

int main()
{
    int n = 10;
    void *ptr = &n;

    printf("Value of n: %d\n", *(int *)ptr);
}