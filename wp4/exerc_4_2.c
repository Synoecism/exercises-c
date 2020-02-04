/*
File name: exerc_4_2.c (or cpp)
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Unsigned char to store all the positions
unsigned char positions;

int main(int argc, char **argv)
{
    //execution command is one argument, therefore 2 = accepting 1 user argument
    if (argc == 2)
    {
        //check if string is either one or two characters
        if (strlen(argv[1]) < 2 && strlen(argv[1]) > 1)
        {
            //check if string is hexadecimal value or not
            if (isxdigit(argv[1]))
            {

                //do some shit here do not know how it works

                //Setting the different characters from the list of arguments as integers to prevent 'invalid operand to binary' error
                int engine_on = atoi(argv[1]);
                int gear_pos = atoi(argv[2]);
                int key_pos = atoi(argv[3]);
                int brake1 = atoi(argv[4]);
                int brake2 = atoi(argv[5]);

            }
            else
            {
                puts("Not a hexadecimal value");
            }
        }
        else
        {
            puts("Input should either be one or two charachters");
        }
    }
    else
    {
        puts("Wrong number of arguments inserted. Exit program.");
    }

    return 0;
}