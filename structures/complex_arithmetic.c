#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <math.h>

#include "../util/input.h"

#define INPUT_SIZE 20

typedef struct
{
    int realPart;
    int imaginaryPart;
} ComplexNumber;

int inputInvalid(char *, char *);
void extractParts(ComplexNumber *, char *);
void printSum(ComplexNumber *, ComplexNumber *);
void printDifference(ComplexNumber *, ComplexNumber *);
void printProduct(ComplexNumber *, ComplexNumber *);

int main(void)
{
    char firstInput[INPUT_SIZE];
    char secondInput[INPUT_SIZE];
    ComplexNumber firstNumber;
    ComplexNumber secondNumber;
    char *inputPattern =
        "^(([-,+]?[0-9]{1,6})|([-,+]?[0-9]{1,6} [-,+] [-,+]?[0-9]{1,6}i))$";

    puts("");
    puts("Welcome to Complex Number Arithmetic!");
    puts("");

    readLine(firstInput, "Enter first number: ");
    while (inputInvalid(firstInput, inputPattern))
    {
        readLine(firstInput, "Enter complex number in rectangular form (a + bi): ");
    }
    puts("");
    readLine(secondInput, "Enter second number: ");
    while (inputInvalid(secondInput, inputPattern))
    {
        readLine(secondInput, "Enter complex number in rectangular form: ");
    }

    extractParts(&firstNumber, firstInput);
    extractParts(&secondNumber, secondInput);
    puts("");
    printSum(&firstNumber, &secondNumber);
    printDifference(&firstNumber, &secondNumber);
    printProduct(&firstNumber, &secondNumber);
    puts("");
}

int inputInvalid(char *string, char *pattern)
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

void extractParts(ComplexNumber *number, char *userInput)
{
    number->realPart = atoi(strtok(userInput, " "));
    char *sign = strtok(NULL, " ");
    if (sign == NULL)
    {
        // No imaginary part.
        number->imaginaryPart = 0;
    }
    else
    {
        int factor = strcmp(sign, "-") == 0 ? -1 : 1;
        number->imaginaryPart = atoi(strtok(NULL, " ")) * factor;
    }
}

void printSum(ComplexNumber *firstNumber, ComplexNumber *secondNumber)
{
    int realTotal = firstNumber->realPart + secondNumber->realPart;
    int imaginaryTotal =
        firstNumber->imaginaryPart + secondNumber->imaginaryPart;

    printf("(%d + %di) + (%d + %di) = (%d + %di)\n",
           firstNumber->realPart, firstNumber->imaginaryPart,
           secondNumber->realPart, secondNumber->imaginaryPart,
           realTotal, imaginaryTotal);
}

void printDifference(ComplexNumber *firstNumber, ComplexNumber *secondNumber)
{
    int realDiff = firstNumber->realPart - secondNumber->realPart;
    int imaginaryDiff =
        firstNumber->imaginaryPart - secondNumber->imaginaryPart;

    printf("(%d + %di) - (%d + %di) = (%d + %di)\n",
           firstNumber->realPart, firstNumber->imaginaryPart,
           secondNumber->realPart, secondNumber->imaginaryPart,
           realDiff, imaginaryDiff);
}

void printProduct(ComplexNumber *firstNumber, ComplexNumber *secondNumber)
{
    double magnitude1 = sqrt(
        firstNumber->realPart * firstNumber->realPart +
        firstNumber->imaginaryPart * firstNumber->imaginaryPart);
    double magnitude2 = sqrt(
        secondNumber->realPart * secondNumber->realPart +
        secondNumber->imaginaryPart * secondNumber->imaginaryPart);
    double angle1 = atan(firstNumber->imaginaryPart / firstNumber->realPart);
    double angle2 = atan(secondNumber->imaginaryPart / secondNumber->realPart);

    double productMagnitude = magnitude1 * magnitude2;
    double productAngle = angle1 + angle2;
    double productReal = productMagnitude * cos(productAngle);
    double productImaginary = productMagnitude * sin(productAngle);

    printf("(%d + %di) x (%d + %di) = (%f + %fi)\n",
           firstNumber->realPart, firstNumber->imaginaryPart,
           secondNumber->realPart, secondNumber->imaginaryPart,
           productReal, productImaginary);
}
