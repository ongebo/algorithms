/*
Store and print fake details about a student with structures.
 */
#include <stdio.h>

typedef struct
{
    unsigned rollNo;
    char *name;
    unsigned age;
    unsigned marks;
} Student;

int main(void)
{
    Student student = {1, "John Doe", 26, 98};
    puts("Fake Student Details:");
    printf("%15s: %u\n", "Roll Number", student.rollNo);
    printf("%15s: %s\n", "Name", student.name);
    printf("%15s: %u\n", "Age", student.age);
    printf("%15s: %u\n", "Marks", student.marks);
}
