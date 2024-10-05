#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node n1 = {10, NULL};
    struct Node n2 = {20, NULL};

    n1.next = &n2;

    struct Node *phead = &n1;

    printf("n1.data = %d, n2.next = %d\n", n1.data, n2.next);
}
