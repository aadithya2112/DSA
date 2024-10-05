#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    return newNode;
}

void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->prev = temp;
        temp->next = newNode;
    }
}

void insertAtData(int posData, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->data != posData)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertBeforeData(int beforeData, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    // Only one node
    if (head->data == beforeData)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (temp->next->data != beforeData)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
}

void insertBeforeData(int beforeData, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    if (head->data == beforeData)
    {
        newNode->next = head;
        head->prev = newNode;
        return;
    }

    while (temp->data != beforeData)
    {
        temp = temp->next;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
    {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
}

void search(int data)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found\n");
}

void popFirst()
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        head = temp->next;
        head->prev = NULL;

        free(temp);
    }
}

void popLast()
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        struct Node *before = temp->prev;
        before->next = NULL;

        free(temp);
    }
}

void popData(int data)
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp->data != data)
        {
            temp = temp->next;
        }
        // if temp is the first node
        if (temp->prev == NULL)
        {
            head = temp->next;
            free(temp);
            return;
        }

        struct Node *before = temp->prev;
        before->next = temp->next;

        // if temp is not the last node
        if (temp->next != NULL)
        {
            temp->next->prev = before;
        }

        free(temp);
    }
}

int main()
{
    insertAtBeginning(20);
    insertAtBeginning(10);

    insertAtEnd(30);
    // 10 20 30 40
    insertAtData(30, 40);

    // popData
    popData(10);
    display();
}