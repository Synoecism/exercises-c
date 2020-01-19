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

#define MAX 100

int main()
{
    char str[MAX]; 
    int len = 0;
    int KEY = 13;
    int level = 77;
    char charvalue;
    char encryptvalue;

    fgets(str, MAX, stdin); 
    len = strlen(str);

    //header for the program
    printf("V - A - EV - A \n");
    
    //len-1 to not print "enter" which has ascii-value 10
    for(int i = 0; i < len-1; i++){
        charvalue = str[i];
        if(str[i] > level){
            encryptvalue = str[i]+-KEY;
        } else {
            encryptvalue = str[i]+KEY;
        }
        printf("%c - %d - %c - %d \n",charvalue,charvalue,encryptvalue,encryptvalue);
    }
    return 0;    
}