#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(void)
{
    regex_t regex;
    char *pattern = "^[0-9]+$";
    char errorMessage[100];
    char *strings[] = {"1234", "john doe", "123name", "0988"};

    int failedToCompile = regcomp(&regex, pattern, REG_EXTENDED);
    if (failedToCompile)
    {
        puts("Could not compile regular expression!");
        exit(1);
    }

    puts("");
    printf("Regular Expression: %s\n", pattern);
    puts("");

    size_t i;
    for (i = 0; i < 4; i++)
    {
        int status = regexec(&regex, strings[i], 0, NULL, 0);
        if (status)
        {
            regerror(status, &regex, errorMessage, sizeof(errorMessage));
            printf("Error Message: %s\n", errorMessage);
            printf("%s doesn't match the regular expression\n", strings[i]);
            puts("");
        }
        else
        {
            printf("%s matches the regular expression\n", strings[i]);
            puts("");
        }
    }
}
