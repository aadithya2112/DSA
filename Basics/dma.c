#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr = (int *)malloc(4);
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    *ptr = 10;
    printf("Value of ptr: %d\n", *ptr);
    free(ptr);
    return 0;
}