#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4};

    int *pa = &arr;

    printf("%d", *(pa + 1));
}