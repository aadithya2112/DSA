/*
A matrix contains more number of ZERO values than NON-ZERO values.
Such matrix is known as sparse matrix.

Linked List representation of Sparse Matrix
- Each node of the linked list contains three fields:
    - row: row index of the element
    - col: column index of the element
    - value: value of the element
    - next: pointer to the next node
*/

struct Node
{
    int row, col, value;
    struct Node *next;
};
