#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point *p;
    struct Point p1 = {1, 2};
    p = &p1;

    printf("x = %d, y = %d\n", p->x, p->y);
    // or
    printf("x = %d, y = %d\n", p1.x, p1.y);
    // or
    printf("x = %d, y = %d\n", (*p).x, (*p).y);
}