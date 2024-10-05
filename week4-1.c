#include <stdio.h>
#include <math.h>

struct Triangle
{
    int a, b, c;
    double area;
};

double calculateArea(int a, int b, int c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void sortTriangles(struct Triangle triangles[], int n)
{
    struct Triangle temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (triangles[j].area > triangles[j + 1].area)
            {
                temp = triangles[j];
                triangles[j] = triangles[j + 1];
                triangles[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of triangles: ");
    scanf("%d", &n);

    struct Triangle triangles[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter sides of triangle %d: ", i + 1);
        scanf("%d %d %d", &triangles[i].a, &triangles[i].b, &triangles[i].c);
        triangles[i].area = calculateArea(triangles[i].a, triangles[i].b, triangles[i].c);
    }

    sortTriangles(triangles, n);

    printf("Triangles sorted by area:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Triangle %d: sides (%d, %d, %d), area: %.2lf\n",
               i + 1, triangles[i].a, triangles[i].b, triangles[i].c, triangles[i].area);
    }

    return 0;
}
