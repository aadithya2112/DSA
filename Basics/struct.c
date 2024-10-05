#include <stdio.h>

struct Student
{
    char name[10];
    float cgpa;
    int age;
};

int main()
{
    struct Student s1 = {"Sanjana", 10, 18};
    struct Student s2 = {"Aadithya", 9.5, 17};

    int n = 2;
    int *pn = &n;

    struct Student *ps1 = &s1;

    printf("Sanjana's age: %d\n", ps1->age);
    printf("Sanjana's age: %d\n", s1.age);

    printf("Sanjana's age: %d\n", (*ps1).age);
}