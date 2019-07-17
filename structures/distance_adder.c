#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

void readLine(char *, char *);
int inputInvalid(char *);
void addDistances(char *, const char *, const char *);
void extractUnits(int *, const char *);

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

void readLine(char *input, char *prompt)
{
    printf("%s", prompt);
    unsigned pointerPosition = 0;
    char c = getchar();
    while (c != '\n')
    {
        input[pointerPosition++] = c;
        c = getchar();
    }
    input[pointerPosition] = '\0';
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
    int result1[3];
    int result2[3];
    extractUnits(result1, distance1);
    extractUnits(result2, distance2);
    int totalFeet = result1[0] + result2[0];
    int totalInches = result1[1] + result2[1];
    sprintf(totalDistance, "%d'%d\"", totalFeet, totalInches);
}

void extractUnits(int *result, const char *distance)
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

    result[0] = atoi(feet);
    result[1] = atoi(inches);
    result[2] = '\0';
}
