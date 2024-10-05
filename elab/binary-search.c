#include <stdio.h>
#include <stdlib.h>

void binarySearch(int arr[], int size, int target)
{
    int l = 0;
    int r = size - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            printf("%d found at location %d", target, mid + 1);
            return;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("Not found! %d is not present in the list", target);
}

int main()
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)(malloc(sizeof(int) * size));

    for (int i = 0; i < size; i++)
    {
        scanf("%d ", &arr[i]);
    }
    int target;
    scanf("%d", &target);
    binarySearch(arr, size, target);
}