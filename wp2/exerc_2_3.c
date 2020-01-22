/*
File name: exerc_x_y.c (or cpp)
Date: YYYY-MM-DD
Group nr 1
Members that contributeto the solutions
Emanuel Dellsén
Niklas Möller
Karl Westgårdh 

Member not present at demonstration time:

Demonstration code: [
<Ass code 1-4> <abc>]Important
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
            if (strcmp(argv[i], argv[i + 1]) == 0)
            {
                printf("\nString compare using strcmp() == true \n");
            }
            else
            {
                printf("\nString compare using strcmp() == false \n");
            }

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

    //assign the longest string as length in forloop
    if (flen < slen)
    {
        len = slen;
    }
    else
    {
        len = flen;
    }

    bool value = true;

    for (int i = 0; i < len; i++)
    {
        if (first[i] != second[i])
        {
            value = false;
        }
    }

    return value;
}