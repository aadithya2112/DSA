#include <stdio.h>

struct Dob
{
    int day;
    int month;
    int year;
};

struct Student
{
    char name[50];
    int age;
    struct Dob dob;
};

int main()
{
    struct Student s1 = {"John", 18, {1, 1, 2000}};
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("DOB: %d/%d/%d\n", s1.dob.day, s1.dob.month, s1.dob.year);
}