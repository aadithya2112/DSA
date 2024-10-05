#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node **head, int coeff, int exp)
{
    struct Node *newNode = createNode(coeff, exp);
    struct Node *current = *head;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node *addPolynomials(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->exp == head2->exp)
        {
            int sumCoeff = head1->coeff + head2->coeff;
            if (sumCoeff != 0)
            {
                addNode(&result, sumCoeff, head1->exp);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exp > head2->exp)
        {
            addNode(&result, head1->coeff, head1->exp);
            head1 = head1->next;
        }
        else
        {
            addNode(&result, head2->coeff, head2->exp);
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        addNode(&result, head1->coeff, head1->exp);
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        addNode(&result, head2->coeff, head2->exp);
        head2 = head2->next;
    }

    return result;
}

void printPolynomial(struct Node *poly)
{
    if (poly == NULL)
    {
        printf("0");
        return;
    }

    int isFirst = 1;
    while (poly != NULL)
    {
        if (poly->coeff > 0 && !isFirst)
        {
            printf("+");
        }
        printf("%dx^%d", poly->coeff, poly->exp);
        isFirst = 0;
        poly = poly->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // First polynomial: 3x^2 + 5x + 2
    addNode(&head1, 3, 2);
    addNode(&head1, 5, 1);
    addNode(&head1, 2, 0);

    // Second polynomial: 4x^2 + 2x + 1
    addNode(&head2, 4, 2);
    addNode(&head2, 2, 1);
    addNode(&head2, 1, 0);

    // Add the polynomials
    struct Node *result = addPolynomials(head1, head2);

    // Print the result
    printf("Sum of Polynomials: ");
    printPolynomial(result);

    // Free the memory
    // Implement free function to release allocated memory
    // ...

    return 0;
}
