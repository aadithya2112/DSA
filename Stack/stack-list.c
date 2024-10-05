#include <stdio.h>

#define MAX_SIZE 100

int top = -1;
int data[MAX_SIZE];

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }
    data[++top] = value;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    top--;
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display();

    printf("After Popped: \n");
    pop();
    pop();

    display(); // Display stack contents again

    return 0;
}
