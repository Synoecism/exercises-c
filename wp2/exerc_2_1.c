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

    //wait for input
    fgets(from,BUFFERSIZE,stdin);

    //SCENARIO A)    
    strcpy(copy,from);

    printf("\n Read and copied by use of strcpy() !: %s \n",copy);

    //SCENARIO B)
    copyString(&to,&from); //Passing the address of the variables and not their values

    printf("\n Read and copied by use of copyString() !: %s \n",to);

    return 0;
}

void copyString(char *to, char *from){
    int len = strlen(from);
    
    for(int i = 0; i < len; i++){
        to[i] = from[i];
    }

    to[len] = '\0'; //Adding \0 to cut off the string
}

