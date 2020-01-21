/* Create a very simple encryption program. The program is based on the principal of “shifts of characters” in the
ASCII-code table. In the example below, A has shifted to N, B to O, etc., that will mean 13 steps in the table.
Only capital letters are viewed in the figure but the same ideas applies to lower case letters. The word HELLO
becomes URYYB after encryption.
The user enters a text and the program prints out the encrypted text. Let the program read character by
character, and encrypt it as above. The program is repeated until EOF indicated the
program ends. (EOF, the user enters Ctrl +z for Windows and Ctrl + d for Linux system).
 */

#include <stdio.h>
#include <string.h> 

int main(void) {

char c;
int shift = 13;
char newWord[100];
char newchar;

strcpy(newWord, ""); //Else I get some fuzzy characters in the beginning of the first string... Why?

/* Caesar Cipher
The logic in the if statement:

Trying to figure it out... 

for example recieving p gives
112 - 97 = 15
15 + 13 = 28
28 % 26 = 2
2 + 97 = 99
99 gives c 
 */

do{

     c = getchar();

     if(c >= 'a' && c <= 'z') {
    newchar = (c - 'a' + shift) % 26 + 'a';    
    strncat(newWord, &newchar, 1); 
    }
    else if(c >= 'A' && c <= 'Z'){
            newchar = (c - 'A' + shift) % 26 + 'A';
    strncat(newWord, &newchar, 1); 
    }
    else if(c == '\n'){
    printf("Encrypted: %s\n", newWord);
    strcpy(newWord, ""); //To empty the string. Might be a very bad solution...
     }

}while(c != EOF);

}