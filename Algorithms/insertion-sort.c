#include <stdio.h>

int main()
{
    int nums[10] = {5, 2, 4, 6, 1, 3, 7, 9, 8, 0};
    // i = 0; i < 10 ; i++
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        int key = nums[i];
        int j = i - 1; // The last element of the sorted subarray.
        // eg i = 1, j = 0

        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }

    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        printf("%d ", nums[i]);
    }
}