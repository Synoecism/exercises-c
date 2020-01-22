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

#define BUFFERSIZE 20
void copyString();

// to read from txt instead of user input in terminal, use < myfile.txt after execution of gcc

int main() {

    char from[BUFFERSIZE];

    //wait for input
    fgets(from,BUFFERSIZE,stdin);

    //SCENARIO A)
    //copy of string (to,from)
    char copy[BUFFERSIZE];
    strcpy(copy,from);

    printf("\n Read and copied by use of strcpy() !: %s \n",copy);

    //SCENARIO B)
    char to[BUFFERSIZE];
    copyString(to,from);

    printf("\n Read and copied by use of copyString() !: %s \n",to);

    return 0;
}

void copyString(char *to, char *from){

    int len = strlen(from);
    
    for(int i = 0; i < len; i++){
        to[i] = from[i];
    }
}