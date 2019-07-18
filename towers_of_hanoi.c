#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "util/input.h"

void solveHanoi(unsigned, int, int, int);
int inputInvalid(char *);

int main(void)
{
    int numberOfDisks;
    char userInput[20];

    puts("*** Welcome to the towers of hanoi solver! ***");
    puts("");
    readLine(userInput, "Enter the number of disks: ");
    while (inputInvalid(userInput))
    {
        readLine(userInput, "Enter a number from 1 to 50: ");
    }

    numberOfDisks = atoi(userInput);
    puts("");
    solveHanoi(numberOfDisks, 0, 1, 2);
    puts("");
}

// Ensure that the user enters a number from 1 to 50.
int inputInvalid(char *input)
{
    size_t i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (!isdigit(input[i]))
        {
            return 1;
        }
    }
    int numberOfDisks = atoi(input);
    if (numberOfDisks < 1 || numberOfDisks > 50)
    {
        return 1;
    }
    return 0;
}

// Print the steps to solving the towers of hanoi puzzle.
void solveHanoi(unsigned numberOfDisks, int start, int end, int temp)
{
    if (numberOfDisks == 1)
    {
        printf("Move disk %u from %d to %d\n", numberOfDisks, start, end);
    }
    else
    {
        solveHanoi(numberOfDisks - 1, start, temp, end);
        printf("Move disk %u from %d to %d\n", numberOfDisks, start, end);
        solveHanoi(numberOfDisks - 1, temp, end, start);
    }
}
