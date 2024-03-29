#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <ctype.h>

#include "../util/input.h"

#define TRUE 1
#define FALSE 0

typedef struct
{
    int feet;
    int inches;
} Distance;

void readLine(char *, char *);
int inputInvalid(char *);
void addDistances(char *, const char *, const char *);
void extractUnits(Distance *, const char *);

int main(void)
{
    char distance1[100];
    char distance2[100];
    char totalDistance[100];
    puts("");
    readLine(distance1, "Enter first distance: ");
    while (inputInvalid(distance1))
    {
        readLine(distance1, "Enter correct distance in ft-in: ");
    }
    puts("");
    readLine(distance2, "Enter second distance: ");
    while (inputInvalid(distance2))
    {
        readLine(distance2, "Enter correct distance in ft-in: ");
    }
    addDistances(totalDistance, distance1, distance2);
    puts("");
    printf("The total distance is: %s\n", totalDistance);
}

int inputInvalid(char *input)
{
    regex_t regex;
    char *pattern = "^[0-9]+'[0-9]+\"$";
    if (regcomp(&regex, pattern, REG_EXTENDED))
    {
        puts("Failed to compile regular expression!");
        exit(1);
    }
    if (regexec(&regex, input, 0, NULL, 0) == 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void addDistances(char *totalDistance, const char *distance1, const char *distance2)
{
    Distance result1;
    Distance result2;
    extractUnits(&result1, distance1);
    extractUnits(&result2, distance2);
    int totalFeet = result1.feet + result2.feet;
    int totalInches = result1.inches + result2.inches;
    sprintf(totalDistance, "%d'%d\"", totalFeet, totalInches);
}

void extractUnits(Distance *result, const char *distance)
{
    char feet[10];
    char inches[10];
    int arraySize = sizeof(distance) / sizeof(distance[0]);
    size_t i;
    for (i = 0; i < arraySize; i++)
    {
        if (isdigit(distance[i]))
        {
            feet[i] = distance[i];
        }
        else
        {
            feet[i] = '\0';
            break;
        }
    }

    size_t c;
    for (++i, c = 0; i < arraySize; c++, i++)
    {
        if (isdigit(distance[i]))
        {
            inches[c] = distance[i];
        }
        else
        {
            inches[c] = '\0';
            break;
        }
    }

    result->feet = atoi(feet);
    result->inches = atoi(inches);
}
