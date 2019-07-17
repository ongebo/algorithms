#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

#include "../util/input.h"

typedef struct
{
    unsigned rollNumber;
    char name[50];
    unsigned chemMarks;
    unsigned mathsMarks;
    unsigned phyMarks;
} Mark;

void getStudentMarks(Mark *, int);
int stringInvalid(char *rollNumber, char *pattern);
void printMarks(const Mark *, int);

int main(void)
{
    Mark marks[5];

    puts("");
    puts("Enter marks for 5 students.");

    // Get marks for first student.
    puts("");
    puts("1st Student");
    getStudentMarks(marks, 0);

    // Get marks for second student.
    puts("");
    puts("2nd Student");
    getStudentMarks(marks, 1);

    // Get marks for third student.
    puts("");
    puts("3rd Student");
    getStudentMarks(marks, 2);

    // Get marks for fourth student.
    puts("");
    puts("4th Student");
    getStudentMarks(marks, 3);

    // Get marks for fifth student.
    puts("");
    puts("5th Student");
    getStudentMarks(marks, 4);

    // Print the student marks.
    puts("");
    printMarks(marks, 5);
}

void getStudentMarks(Mark *marks, int number)
{
    char rollNumber[10];
    char chemMarks[50];
    char mathsMarks[50];
    char phyMarks[50];

    readLine(rollNumber, "Roll Number: ");
    while (stringInvalid(rollNumber, "^[0-9]+$"))
    {
        readLine(rollNumber, "Enter a valid roll number: ");
    }

    readLine(marks[number].name, "Student Name: ");
    while (stringInvalid(marks[number].name, "^[a-zA-Z]{3,30}( [a-zA-Z]{3,30})*$"))
    {
        readLine(marks[number].name, "Enter a valid student name: ");
    }

    readLine(chemMarks, "Chemistry Marks: ");
    while (stringInvalid(chemMarks, "^((100)|([1-9][0-9])|([0-9]))$"))
    {
        readLine(chemMarks, "Enter valid marks: ");
    }

    readLine(mathsMarks, "Maths Marks: ");
    while (stringInvalid(mathsMarks, "^((100)|([1-9][0-9])|([0-9]))$"))
    {
        readLine(mathsMarks, "Enter valid marks: ");
    }

    readLine(phyMarks, "Physics Marks: ");
    while (stringInvalid(phyMarks, "^((100)|([1-9][0-9])|([0-9]))$"))
    {
        readLine(phyMarks, "Enter valid marks: ");
    }

    marks[number].rollNumber = atoi(rollNumber);
    marks[number].chemMarks = atoi(chemMarks);
    marks[number].mathsMarks = atoi(mathsMarks);
    marks[number].phyMarks = atoi(phyMarks);
}

int stringInvalid(char *string, char *pattern)
{
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED))
    {
        puts("Failed to compile regular expression");
        puts("Exiting program...");
        exit(1);
    }
    return regexec(&regex, string, 0, NULL, 0);
}

void printMarks(const Mark *marks, int numberOfMarks)
{
    puts("STUDENT MARKS\n");

    size_t c;
    for (c = 0; c < numberOfMarks; c++)
    {
        printf("%s:\n", marks[c].name);
        printf("Chemistry %u%s\n", marks[c].chemMarks, "%");
        printf("Maths %u%s\n", marks[c].chemMarks, "%");
        printf("Physics %u%s\n", marks[c].chemMarks, "%");
        puts("");
    }
}
