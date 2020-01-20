/*
File name: exerc_x_y.c (or cpp)
Date: 2020-01-19
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
#include <ctype.h>

#define MAX 100
#define upper_level 77
#define lower_level 109

int main()
{
    char str[MAX];
    int len = 0;
    int KEY = 13;
    char charvalue;
    char encryptvalue;
    char word[MAX];

    fgets(str, MAX, stdin);
    len = strlen(str);

    //header for the program
    printf("V - A - EV - A \n");

    //len-1 to not print "enter" which has ascii-value 10
    for (int i = 0; i < len - 1; i++)
    {

        char correct;

        if (i < 1)
        {
            correct = toupper(str[i]);
            if (correct > upper_level)
            {
                encryptvalue = correct + -KEY;
            }
            else
            {
                encryptvalue = correct + KEY;
            }
        }
        else
        {
            correct = tolower(str[i]);
            if (correct > lower_level)
            {
                encryptvalue = correct + -KEY;
            }
            else
            {
                encryptvalue = correct + KEY;
            }
        }
        word[i] = encryptvalue;
        printf("%c - %d - %c - %d \n", correct, correct, encryptvalue, encryptvalue);
    }
    printf("\n Word is: %s \n",word);
    return 0;
}