#include <stdio.h>

// Gets substring from string, given string, start and end value
// Remade from the strstr sourcecode to try and understand it better
int isSubStrInStr(register char *string, char *substring)
{
    register char *a, *b;

    b = substring;

    if (*b == 0)
    {
        return 1;
    }

    for (; *string != 0; string += 1)
    {
        if (*string != *b)
        {
            continue;
        }
        a = string;
        while (1)
        {
            if (*b == 0)
            {
                return 1;
            }
            if (*b++ != *a++)
            {
                break;
            }
        }
        b = substring;
    }

    return 0;
}
