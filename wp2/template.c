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
#define MAX 100

int main()
{
    int n = 0;
    char c;
    char text[MAX];
    while((c = getchar()) !='\n'){
        text[n]=c;
        n++;
    };
    text[n] ='\0';

    return 0;
}