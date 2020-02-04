/*
File name: exerc_4_1.c (or cpp)
Date: 2020-02-02
Group nr 1
Members that contribute to the solutions
Emanuel Dellsén
Niklas Möller
Karl Westgårdh 

Member not present at demonstration time:
NONE

Demonstration code: []
Important
No code no exercise points!
*/

//Reference for HEX and Bytes: http://csweb.cs.wfu.edu/~turketwh/CSC101/Spring2011/BinaryHex.pdf

#include <stdio.h>
#include <stdlib.h>

unsigned char positions; //Unsigned char to store all the positions

int main(int argc, char **argv)
{
    if (argc == 6) //Since the exerc_4_1.exe accounts as an argument
    {
        //Setting the different characters from the list of arguments as integers to prevent 'invalid operand to binary' error
        int engine_on = atoi(argv[1]);
        int gear_pos = atoi(argv[2]);
        int key_pos = atoi(argv[3]);
        int brake1 = atoi(argv[4]);
        int brake2 = atoi(argv[5]);

        positions |= brake2; //Sets the Least Significant Bit (LSB), bit nr 0

        //Prints to enhance understanding what happens in memory
        //printf("The byte to hexadecimal after insert 1: %X \n", positions);

        positions |= (brake1 << 1); //Shifting to bit nr 1 

        //printf("The byte to hexadecimal after insert 2: %X \n", positions);

        positions |= (key_pos << 2); //Shifting to bit nr 2

        //printf("The byte to hexadecimal after insert 3: %X \n", positions);

        positions |= (gear_pos << 4); //Shifting to bit nr 4
        
        //printf("The byte to hexadecimal after insert 4: %X \n", positions);

        positions |= (engine_on << 7); //Shifting to bit nr 7

        printf("The byte to hexadecimal gives: %X \n", positions); // %X print out hexadecimal as upper case letters
    }
    else
    {
        puts("Wrong number of arguments inserted. Exit program.");
    }

    return 0;
}