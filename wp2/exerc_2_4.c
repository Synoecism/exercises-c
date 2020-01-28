/*
File name: exerc_2_4.c (or cpp)
Date: 2020-01-28
Group nr 1
Members that contribute to the solutions
Emanuel Dellsén
Niklas Möller
Karl Westgårdh 

Member not present at demonstration time:
NONE

Demonstration code: [27455]
Important
No code no exercise points!
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 101

int main()
{
    char word[MAX];
    int len;
    int j;
    bool value;

    //get input from user
    fgets(word, MAX, stdin);

    //get length of word (ignore enter by -1)
    len = strlen(word) - 1;
    j = len - 1;

    value = true;

    for (int i = 0; i < j; i++)
    {
        if (word[i] != word[j])
        {
            value = false;
            break;
        }
        j--;
    }

    if (value)
    {
        printf("It's a palindrome\n");
    }
    else
    {
        printf("Not a palindrome\n");
    }

    return 0;
}