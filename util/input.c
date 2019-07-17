#include <stdio.h>

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
