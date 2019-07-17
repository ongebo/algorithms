#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

#include "../util/input.h"

typedef struct
{
    unsigned rollNumber;
    char *name;
    unsigned chemMarks;
    unsigned mathsMarks;
    unsigned phyMarks;
} Mark;

void getStudentMarks(Mark *, int);
int stringInvalid(char *rollNumber, char *pattern);

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
}

void getStudentMarks(Mark *marks, int number)
{
    char rollNumber[10];
    char name[50];
    char chemMarks[50];
    char mathsMarks[50];
    char phyMarks[50];

    readLine(rollNumber, "Roll Number: ");
    while (stringInvalid(rollNumber, "^[0-9]+$"))
    {
        readLine(rollNumber, "Enter a valid roll number: ");
    }

    readLine(name, "Student Name: ");
    while (stringInvalid(name, "^[a-zA-Z]{3,30}( [a-zA-Z]{3,30})*$"))
    {
        readLine(name, "Enter a valid student name: ");
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
    marks[number].name = name;
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
