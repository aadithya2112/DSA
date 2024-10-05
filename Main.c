#include <stdio.h>

int queue[10];

int front = -1, rear = -1;

void enqueue(int data)
{
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    queue[front] = 0;
    front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
}