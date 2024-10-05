#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value)
{
    struct Node *newNode = createNode(value);
    if (top == NULL)
    {
        top = newNode;
        return;
    }

    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
    display();

    return 0;
}