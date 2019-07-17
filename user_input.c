#include <stdio.h>
#include "util/input.h"

int main(void)
{
    char buffer[100]; // Size must be explicitly specified.
    printf("%s: ", "Enter a string");

    // Read string using the standard fgets() function.
    fgets(buffer, 100, stdin);
    printf("%s: %s\n", "You entered", buffer);
    puts("Continuing...\n");

    // Read string using the readLine() function.
    readLine(buffer, "Enter another string: ");
    printf("%s: %s\n\n", "You entered", buffer);
    puts("Terminating...");
}
