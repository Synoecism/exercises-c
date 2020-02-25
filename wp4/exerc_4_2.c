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
#include <math.h>

//inspiration: https://codeforwin.org/2015/09/c-program-to-convert-hexadecimal-to-decimal-number-system.html
//reference: https://coolconversion.com/math/binary-octal-hexa-decimal/Convert_binary__10101011_to_hex_

unsigned char unc;
unsigned char nunc;
char hex[17];

int main(int argc, char **argv)
{
    //execution command is one argument, therefore 2 = accepting 1 user argument
    if (argc == 2)
    {
        int len = 0;
        int i;
        int val;
        long long decimal;
        int engine_on;
        int gear_pos;
        int key_pos;
        int brake1;
        int brake2;

        //copy input to hex
        strcpy(hex, argv[1]);

        /* Find the length of total number of hex digit */
        len = strlen(hex);
        len--;

        /*Iterate over each hex digit*/

        for (i = 0; hex[i] != '\0'; i++)
        {

            /* Find the decimal representation of hex[i] */
            if (hex[i] >= '0' && hex[i] <= '9')
            {
                //convert from ascii value to hexadecimal value
                val = hex[i] - 48;
            }
            else if (hex[i] >= 'a' && hex[i] <= 'f')
            {
                //convert from ascii value to hexadecimal value
                val = hex[i] - 97 + 10;
            }
            else if (hex[i] >= 'A' && hex[i] <= 'F')
            {
                //convert from ascii value to hexadecimal value
                val = hex[i] - 65 + 10;
            }
            //conver from hexadecimal value to decimal value
            decimal += val * pow(16, len);
            len--;
        }

        printf("Hexadecimal number = %s\n", hex);
        printf("Decimal number = %lld\n", decimal);

        //convert from long long to unsigned char
        unc = (unsigned char)decimal;

        printf("Byte of unc in hexadecimal: %X \n", unc);
        printf("Byte of unc in decimal: %d \n", unc);

        //get binary value of position 7 in byte
        engine_on = ((unc >> 7) & 0x01);

        //move value from unc pos 4 to nunc pos 0
        nunc |= (((unc >> 4) & 0x01) << 0);

        //move value from unc pos 5 to nunc pos 1
        nunc |= (((unc >> 5) & 0x01) << 1);

        //move value from unc pos 4 to nunc pos 0
        nunc |= (((unc >> 6) & 0x01) << 2);

        //assign the decimal value of unsigned char to gear_pos
        gear_pos = (int)nunc;

        //reset nunc for reuse
        nunc = 0;

        //move value from unc pos 2 to nunc pos 0
        nunc |= (((unc >> 2) & 0x01) << 0);

        //move value from unc pos 3 to nunc pos 0
        nunc |= (((unc >> 3) & 0x01) << 1);

        //assign the decimal value of unsigned char to gear_pos
        key_pos = (int)nunc;

        //get binary value of position 1 in byte
        brake1 = ((unc >> 1) & 0x01);

        //get binary value of position 1 in byte
        brake2 = ((unc >> 0) & 0x01);

        //print the result
        printf("\n Name\t\tValue");
        printf("\n-----------------------------");
        printf("\nengine_on\t%d", engine_on);
        printf("\ngear_pos\t%d", gear_pos);
        printf("\nkey_pos\t\t%d", key_pos);
        printf("\nbrake1\t\t%d", brake1);
        printf("\nbrake2\t\t%d", brake2);
        printf("\n");
    }
    else
    {
        puts("Wrong amount of arguments. Exiting program.");
    }
    return 0;
}