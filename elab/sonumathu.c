#include <stdio.h>

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d ", &a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            for (int k = j; k < 5; k++)
            {
                int p = a[i] + a[j] + a[k];
            }
        }
    }
}