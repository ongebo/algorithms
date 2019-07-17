#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

char *readLine(char *);
int inputInvalid(char *);

int main(void)
{
    puts("");
    char *distance1 = readLine("Enter first distance: ");
    puts("");
    while (inputInvalid(distance1))
    {
        distance1 = readLine("Enter correct distance in ft-in: ");
    }
    puts("");
    char *distance2 = readLine("Enter second distance: ");
    while (inputInvalid(distance2))
    {
        distance2 = readLine("Enter correct distance in ft-in: ");
    }
}

char *readLine(char *prompt)
{
    printf("%s", prompt);
    static char line[100];
    unsigned int pointerPosition = 0;
    char c = getchar();
    while (c != '\n')
    {
        line[pointerPosition++] = c;
        c = getchar();
    }
    line[pointerPosition] = '\0';
    return line;
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
