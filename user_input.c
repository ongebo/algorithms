#include <stdio.h>

char *readLine(char *);

int main(void)
{
    char buffer[100]; // Size must be explicitly specified.
    printf("%s: ", "Enter a string");

    // Read string using the standard fgets() function.
    fgets(buffer, 100, stdin);
    printf("%s: %s\n", "You entered", buffer);
    puts("Continuing...\n");

    // Read string using the readLine() function.
    char *userInput = readLine("Enter another string: ");
    printf("%s: %s\n\n", "You entered", userInput);
    puts("Terminating...");
}

// Read and return a string from the user.
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
