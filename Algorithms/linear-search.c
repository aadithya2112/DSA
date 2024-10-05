#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // creating an array dynamically
    int *arr = (int *)malloc(size * sizeof(int));

    // get input
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // linear search get key
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // linear search
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("Key found at %d", i);
            return 0;
        }
    }
    printf("Key not found");
}