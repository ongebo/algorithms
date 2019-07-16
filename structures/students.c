/*
Store details about 5 students and print those of the student with
roll number 2.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "student.h"

int main(void)
{
    Student students[5];
    char *names[5] =
        {"John Doe", "Jane Doe", "Alan Shearer", "Jon Oliver", "Tim Gates"};
    srand(time(NULL));

    size_t i;
    for (i = 0; i < 5; i++)
    {
        students[i].rollNo = i + 1;
        students[i].name = names[i];
        students[i].age = 18 + rand() % 17;
        students[i].marks = 60 + rand() % 30;
    }

    Student *student2 = students + 1;
    puts("Details for student 2");
    printf("%15s: %u\n", "Roll Number", student2->rollNo);
    printf("%15s: %s\n", "Name", students->name);
    printf("%15s: %u\n", "Age", student2->age);
    printf("%15s: %u\n", "Marks", student2->marks);
}
