#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// read first char
// while currchar not 0:
//   if different to last char:
//      add current int and char to end of zipped string
//      initialize count at 1 and last char = curr char
//  else:
//      add 1 to count
//
// How do I carry the value from one while loop to the other?
//
// Initialize while loop
//
//
//
//
//
//
//
//
//

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    // Initialize variables
    register char *b;   // pointer for curr char in buffer
    char a = '\0';      // this will save the last char
    uint32_t count = 0; // 4 byte int for zipping purpose
    char buffer[1024];  // buffer for the characters

    // Read in the different files
    for (int i = 1; i < argc; i++)
    {
        // check file exists
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wzip: cannot open file\n");
            return (1);
        }

        // get a line, max size = size of buffer
        while (fgets(buffer, sizeof(buffer), fp))
        {

            b = buffer; // set the pointers
            for (; *b != 0; b += 1)
            {
                if (a != *b && a != '\0')
                {
                    fwrite(&count, sizeof(count), 1, stdout); // output the count in binary

                    fwrite(&a, 1, 1, stdout); // output the character in binary
                    count = 0;                // reinitialize the count
                }

                count++; // increment the count
                a = *b;  // push the a pointer to the new character
            }
        }
    }
    // Print out the final count at the end of the file
    fwrite(&count, sizeof(count), 1, stdout);
    fwrite(&a, 1, 1, stdout);

    return 0;
}