#include <stdio.h>
#include <stdlib.h>
#include "isStringInSubstring.h"

// wgrep function. Takes in string to search and multiple files, prints lines where string appears
int main(int argc, char *argv[])
{

    // If no command line arguments are passed
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    // Initialize the buffer and search term
    char *search = argv[1];
    char *buffer;
    size_t bufsize = 32;
    buffer = (char *)malloc(bufsize * sizeof(char));

    // If filename isn't given, take user input
    if (argc == 2)
    {
        while (getline(&buffer, &bufsize, stdin) != -1)
        {
            // Check if substring in line
            if (isSubStrInStr(buffer, search))
            {
                printf("%s", buffer);
            }
        }
    }

    // Iterate through the different filenames
    for (int i = 2; i < argc; i++)
    {
        // check file exists
        FILE *fp = fopen(argv[i], "r");

        // Throw error if file doesn't exist
        if (fp == NULL)
        {
            printf("wgrep: cannot open file\n");
            return (1);
        }

        // Check haven't reached end of string
        while (getline(&buffer, &bufsize, fp) != -1)
        {
            // Check if substring in line
            if (isSubStrInStr(buffer, search))
            {
                printf("%s", buffer);
            }
        }
    }
    // Free the allocated memory
    free(buffer);
    return 0;
}