#include <stdio.h>

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        // check file exists
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            return (1);
        }

        // create a buffer and load the first n bytes on it
        char buffer[1024];

        // get a line, max size = size of buffer
        while (fgets(buffer, sizeof(buffer), fp))
        {
            printf("%s", buffer);
        }
    }

    return (0);
}
