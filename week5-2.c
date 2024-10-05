#include <stdio.h>
#include <stdarg.h>

int sumOfIntegers(int count, ...)
{
    va_list args;
    va_start(args, count);

    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        int num = va_arg(args, int);
        sum += num;
    }

    va_end(args); // Clean up the argument list
    return sum;
}

// Main function
int main()
{
    // Call variadic function with different number of arguments
    printf("Sum of 3, 5, 10: %d\n", sumOfIntegers(3, 3, 5, 10));
    printf("Sum of 1, 2, 3, 4, 5: %d\n", sumOfIntegers(5, 1, 2, 3, 4, 5));
    printf("Sum of 7, 14: %d\n", sumOfIntegers(2, 7, 14));

    return 0;
}
