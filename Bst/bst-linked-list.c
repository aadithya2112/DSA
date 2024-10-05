#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    return newNode;
}

void insert(int data)
{
    struct Node *newNode = createNode(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    struct Node *current = root;
    struct Node *parent = NULL;
    while (1)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
            if (current == NULL)
            {
                parent->left = newNode;
                return;
            }
        }
        else
        {
            current = current->right;
            if (current == NULL)
            {
                parent->right = newNode;
                return;
            }
        }
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    insert(10);
    insert(5);
    insert(15);
    insert(3);
    insert(8);
    insert(12);
    insert(18);
    printf("Inorder traversal of BST: ");
    inorder(root);
    return 0;
}