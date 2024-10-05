#include <stdio.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    int data[MAX_SIZE];
};

struct Stack stack;

void push(int value)
{
    if (stack.top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }

    stack.data[++stack.top] = value;
}

void pop()
{
    if (stack.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    stack.top--;
}

void display()
{
    if (stack.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = stack.top; i >= 0; i--)
    {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

int main()
{
    stack.top = -1;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display();

    printf("After Popped: \n");
    pop();
    pop();

    display();

    return 0;
}