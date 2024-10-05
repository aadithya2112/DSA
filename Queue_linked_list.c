#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    return newNode;
}

void enqueue(int data)
{
    struct Node *newNode = createNode(data);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty!");
    }
    struct Node *temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    struct Node *temp = front;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    display();
}