/*
File name: exerc_2_1.c (or cpp)
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

// to read from txt instead of user input in terminal, use < myfile.txt after execution of gcc

#include <stdio.h>
#include <string.h>

//Buffer is 21 to enable input of 20 char
#define BUFFERSIZE 21 
void copyString();

int main() {

    char from[BUFFERSIZE];
    char copy[BUFFERSIZE];
    char to[BUFFERSIZE];

    //Wait for input
    fgets(from,BUFFERSIZE,stdin);

    //SCENARIO A)    
    strcpy(copy,from);
    printf("\n Read and copied by use of strcpy() !: %s \n",copy);

    //SCENARIO B)
    copyString(&to,&from);
    printf("\n Read and copied by use of copyString() !: %s \n",to);

    return 0;
}

void copyString(char *to, char *from){
    int len = strlen(from);
    
    for(int i = 0; i < len; i++){
        to[i] = from[i];
    }
    //cut of string at end of string
    to[len] = '\0';
}

