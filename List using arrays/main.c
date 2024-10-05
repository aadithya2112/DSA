#include <stdio.h>
#include <stdlib.h>

struct List
{
    int *arr;
    int size;     // current size of the list
    int capacity; // max size of the list
};

struct List *createList(int capacity)
{
    struct List *list = (struct List *)malloc(sizeof(struct List));
    list->arr = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// append
void append(struct List *list, int value)
{
    if (list->size < list->capacity)
    {
        list->arr[list->size] = value;
        list->size++;
    }
    else
    {
        printf("List is full\n");
    }
}

// pop
int main()
{
    struct List *list = createList(5);
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    append(list, 5);
    append(list, 6);
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->arr[i]);
    }
    return 0;
}
