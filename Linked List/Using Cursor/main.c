#include <stdio.h>

struct Node
{
    int data;
    int nextpos;
};

struct Node cursorSpace[100];

// initally there no nodes in the list
// so head is -1, its like NULL
int head = -1;
int cursor = 0; // cursor is used to keep track of the next free node

void display()
{
    int temp = head;

    while (temp != -1)
    {
        printf("Data: %d\n", cursorSpace[temp].data);
        temp = cursorSpace[temp].nextpos;
    }
}

void initCursorSpace()
{
    for (int i = 0; i < 100; i++)
    {
        cursorSpace[i].nextpos = i + 1;
    }
    cursorSpace[99].nextpos = -1;
}

void insertAtBeginning(int data)
{
    if (cursor == -1)
    {
        printf("Linked list is full\n");
        return;
    }
    int newNode = cursorSpace[cursor].nextpos;
    cursorSpace[cursor].nextpos = cursorSpace[newNode].nextpos;
    cursorSpace[newNode].data = data;
    cursorSpace[newNode].nextpos = head;
    head = newNode;
}
