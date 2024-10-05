#include <stdio.h>

int calculateTotalMarks(int marks[], int num_students)
{
    int total = 0;
    for (int i = 0; i < num_students; i++)
    {
        total += marks[i];
    }
    return total;
}

// Main function
int main()
{
    int num_students;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    int marks[num_students];

    // Input the marks of the students
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    // Calculate and print the total marks
    int total = calculateTotalMarks(marks, num_students);
    printf("Total marks: %d\n", total);

    return 0;
}
