#include <stdio.h>

void solveHanoi(unsigned, int, int, int);

int main(void)
{
    unsigned int numberOfDisks;

    puts("*** Welcome to the towers of hanoi solver! ***");
    puts("");
    printf("%s: ", "Enter the number of disks");

    scanf("%u", &numberOfDisks);
    puts("");
    solveHanoi(numberOfDisks, 0, 1, 2);
    puts("");
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
