#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
}

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    return node;
}

void insertAtBeginning(int data)
{
    // STEP 1: Create the new node to be inserted
    struct Node *newNode = createNode(data);

    // STEP 2: Point the the new node to the first elment in the linked list
    // STEP 2.1: To do step 2 first we should make sure our linked list is not empty (head != NULL)
    // HEAD will be pointing to NULL, if the linked list is empty
    if (head == NULL)
    {
        head = newNode;
    }

    else
    {
        // STEP 2:
        newNode->next = head;

        // STEP 3: Point head to the new Node
        head = newNode;
    }
}

void insertAtEnd(int data)
{
    // STEP 1: Create the node to be inserted
    struct Node *newNode = createNode(data);

    // STEP 2: Check if the linked list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // STEP 3: Traverse the linked list to get to the last node
        // 1 -> 2 -> 3 -> NULL
        // temp = 3
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtData(int posData, int data)
{
    // STEP 1: Create the node to be inserted
    struct Node *newNode = createNode(data);

    // STEP 2: Check if the linked list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        // STEP 3: Traverse the linked list to get to the node with the data
        struct Node *temp = head;
        while (temp->data != posData)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = newNode;
            return;
        }

        // STEP 4: Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void search(int data)
{
    struct Node *temp = head;

    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data found at %d\n", count);
            return;
        }
        count++;
        temp = temp->next;
    }
    printf("Data not found\n");
}

void popFirst()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void popLast()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void popData(int data)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp->data == data)
    {
        head = temp->next;
        free(temp);
        return;
    }
    // or
    // if (temp->data == data)
    // {
    //     popFirst();
    //     return;
    // }

    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    insertAtBeginning(20);
    // insertAtBeginning(10);
    // insertAtEnd(30);
    // 10, 20
    // 10, 15, 20
    // insertAtData(20, 15);
    // popData(10);
    insertAtData(20, 15);

    display();
}