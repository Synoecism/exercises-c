/*
File name: exerc_x_x.c (or cpp)
Date: YYYY-MM-DD
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for atoi

//reference table: https://kb.iu.edu/d/afdl
//refernece hex to binary: https://coolconversion.com/math/binary-octal-hexa-decimal/Convert_binary__10101011_to_hex_

#define MAX 100

void getInput(char *ptr_buffer);
void hexToBin(unsigned char byte);

int main()
{
    //init of index and ptr
    char index[MAX];
    char *ptr_index = index;

    //init of index and ptr
    char value[MAX];
    char *ptr_value = value;

    //Unsigned char to store all the positions
    unsigned char byte;

    puts("Exit by pressing: q");

    while (*ptr_index != 'q')
    {
        puts("Specify position of bit to shift in byte");
        getInput(ptr_index);

        puts("Specify value of bit to shift in byte");
        getInput(ptr_value);

        //check of inputed value is an integer
        if (atoi(ptr_value) > -1)
        {
            if (atoi(ptr_value) == 0)
            {
                //Sets the Least Significant Bit (LSB), bit nr 0
                byte |= atoi(ptr_value);
            }
            else
            {
                //Shifting to bit nr (user_input)
                byte |= (atoi(ptr_value) << atoi(ptr_index));
            }

            //print hexadecimal value of byte
            printf("Byte value in hexadecimal: \t %X \n", byte);

            //print value of byte as binary
            hexToBin(byte);
        }
    }

    return 0;
}

void getInput(char *ptr_buffer)
{
    //get input
    fgets(ptr_buffer, MAX, stdin);

    //remove enter of input
    ptr_buffer[strlen(ptr_buffer) - 1] = '\0';
}

void hexToBin(unsigned char byte)
{
    //convert unsigned char byte to int value (0-255)
    int i = (int)byte;

    //print decimal value of byte
    printf("Byte value in decimal: \t\t %d \n", i);

    //initalize char array to store binary values of char byte (will be init as [0,0,0,0,0,0,0,0])
    int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    //first binary value is placed at last index in binary-array
    int j = 7;

    //divide byte (byte)base10 successively by 2 until the quotient is 0 (i = 0)
    while (i != 0)
    {
        //assign a binary value to char array which is remainder of division (0 or 1)
        binary[j] = i % 2;

        //update i value according to while-loop header
        i = i / 2;

        //decrement j to move the pointer in the array where binary values are stored
        j--;
    }

    //a godforsakenly ugly print displaying the byte value in binary
    printf("Byte value in binary: \t\t %d %d %d %d %d %d %d %d \n", binary[0], binary[1], binary[2], binary[3], binary[4], binary[5], binary[6], binary[7]);

    //end with end of fline
    printf("\n");
}