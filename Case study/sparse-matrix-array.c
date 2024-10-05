#include <stdio.h>

void transpose(int matrix[3][5])
{
    int temp[5][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            temp[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int sparseMatrix[3][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0}};

    // to get number of non-zero values
    int size = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    int compactMatrix[3][size];
    int k = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", compactMatrix[i][j]);
        }
        printf("\n");
    }
}