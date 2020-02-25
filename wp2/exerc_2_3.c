/*
File name: exerc_2_3.c (or cpp)
Date: 2020-01-28
Group nr 1
Members that contribute to the solutions
Emanuel Dellsén
Niklas Möller
Karl Westgårdh 

Member not present at demonstration time:
NONE

Demonstration code: [x]
Important
No code no exercise points!
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFERSIZE 20

bool stringCompare();

int main(int argc, char **argv)
{
    //if statement to invalidate input when more then two strings
    if (argc <= 3)
    {
        //start at index 1 to exclude execute command
        for (int i = 1; i < argc - 1; i++)
        {
            //compare with library function
            if (strcmp(argv[i], argv[i + 1]) == 0)
            {
                printf("\nString compare using strcmp() == true \n");
            }
            else
            {
                printf("\nString compare using strcmp() == false \n");
            }

            //compare with own constructed function
            if (stringCompare(argv[i], argv[i + 1]))
            {
                printf("String compare using stringCompare() == true \n");
            }
            else
            {
                printf("\nString compare using stringCompare() == false \n");
            }
        }
    }
    else
    {
        printf("Program only compares two strings.");
    }

    return 0;
}

bool stringCompare(char *first, char *second)
{
    //get array size in indicies (not byte size)
    int flen = strlen(first);
    int slen = strlen(second);
    int len;

    //if the string are of different length, invalidate comparison
    if (flen < slen){
        return false;
    }

    len = flen;

    for (int i = 0; i < len; i++)
    {
        if (first[i] != second[i])
        {
            //break if comparison is invalid
            return false;
        }
    }
    //if reached, comparison is valid
    return true;
}