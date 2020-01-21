//Write a program that reads in a sentence of MAX characters and counts the number of words in it.
//The number of words should then be printed out on the console window.

#include <stdio.h>

int main(void) {

int MAX_CHAR = 30;

char c;
int characters = 0;
int words = 0;

printf("Please write a sentence with MAX 30 characters\n");

do{
     c = getchar();
if ( c == '\n' ) { 
     goto Finished;  //Could be replaced with BREAK
}
characters++;
if ( c == ' ') { 
    words++;
}

}while(characters < MAX_CHAR); //DOES NOT CUT OFF THE LOOP (WHY?)

Finished:
printf( "In the sentence you wrote %d words, \n", words);

}