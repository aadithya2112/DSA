#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    int age;
    float gpa;
};

int main()
{
    struct Student s1 = {"John", 20, 3.5};
    struct Student s2 = {"Jane", 21, 3.6};
    struct Student s3 = {"Jack", 22, 3.7};
    struct Student s4 = {"Jill", 23, 3.8};

    struct Student students[] = {s1, s2, s3, s4};

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
    {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }
}