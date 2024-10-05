/*
There are n people standing in a circle waiting to be executed. The counting
out begins at some point in the circle and proceeds around the circle in a fixed
direction. In each step, a certain number of people are skipped and the next
person is executed. The elimination proceeds around the circle (which is
becoming smaller and smaller as the executed people are removed), until
only the last person remains, who is given freedom. Given the total number of
persons n and a number m which indicates that m-1 persons are skipped and
m-th person is killed in circle. The task is to choose the place in the initial
*/

// n = 5, m = 2
// solution: 3

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    return newNode;
}

// Create a circular linked list with n nodes
// Eg if n = 5, the linked list will be 1 -> 2 -> 3 -> 4 -> 5 -> 1
void createCircularLinkedList(int n)
{
    // temp holds the address of the last node
    struct Node *temp = head;
    for (int i = 1; i <= n; i++)
    {
        struct Node *newNode = createNode();
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp->next = head;
}

void display()
{
    struct Node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int josephProblem(int n, int m)
{
    struct Node *temp = head;
    while (temp->next != temp)
    {
        for (int i = 1; i < m - 1; i++)
        {
            temp = temp->next;
        }
        struct Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        temp = temp->next;
    }
    return temp->data;
}

int main()
{
    int n, m;

    printf("Length of circle: n = ");
    scanf("%d", &n);

    printf("Count to choose the next person: m = ");
    scanf("%d", &m);

    createCircularLinkedList(n);
    display();

    int result = josephProblem(n, m);
    printf("The chosen place is %d\n", result);
}