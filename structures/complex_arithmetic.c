#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#include "../util/input.h"

#define INPUT_SIZE 20

int inputInvalid(char *, char *);

int main(void)
{
    char firstNumber[INPUT_SIZE];
    char secondNumber[INPUT_SIZE];
    char *inputPattern =
        "^(([-,+]?[0-9]{1,6})|([-,+]?[0-9]{1,6} [-,+] [-,+]?[0-9]{1,6}i))$";

    puts("");
    puts("Welcome to Complex Number Arithmetic!");
    puts("");

    readLine(firstNumber, "Enter first number: ");
    while (inputInvalid(firstNumber, inputPattern))
    {
        readLine(firstNumber, "Enter complex number in rectangular form: ");
    }
    puts("");
    readLine(secondNumber, "Enter second number: ");
    while (inputInvalid(secondNumber, inputPattern))
    {
        readLine(secondNumber, "Enter complex number in rectangular form: ");
    }
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
