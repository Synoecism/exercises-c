/*
File name: exerc_2_7.c (or cpp)
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //import of boolean type
#include <ctype.h>   // import for isdigit
#include <string.h>
#include <math.h>

void readPersnr(char *person);
int controlDigit(const char *persnr);
bool isIntegers(char *buf);
bool isPnr(char *buf);
int charToInt(char c);
char buf[9];

//Input checking from http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html

int main(void)
{
    do
    {
        readPersnr(buf);
    } while (buf[0] != 'q'); // Break program when user types 'q'
}

void readPersnr(char *person)
{
    int ctrlDigit;
    printf("Enter a personal number: \n");
    //reads input with fgets(), using standard input stdin. Checks we don't overflow buffer
    if (fgets(person, 1024, stdin))
    {
        //check if input is integers

        if (isIntegers(person))
        {
            if (isPnr(person))
            {
                printf("This is a correct personnummer: %s\n", person);
            }
            else
            {
                //do nothing - return to while
                printf("Not a valid personummer.\n");
            }
        }
        else
        {
            if (person[0] == 'q')
            {
                printf("Exiting program... ;) \n");
            }
            else
            {
                //do nothing - return to while
                printf("Not valid input. Please only use integers.\n");
            }
        }
    }
}

int controlDigit(const char *persnr)
{
    int sum;
    float ctrldigit;
    int i;
    int len;
    int multiplier;

    // set sum to 0 in the beginning - important!
    sum = 0;

    //len -2 to not include controldigit while validating controldigit
    len = strlen(persnr) - 2;
    multiplier = 1;

    for (i = 0; i < len; i++)
    {

        if (multiplier == 2)
        {
            multiplier = multiplier / 2;
        }
        else
        {
            multiplier = multiplier * 2;
        }

        int f = (charToInt(persnr[i]) * multiplier);

        //check if value is higher then 9, if true, add to sum as seperate digits (ie 13 -> 1+3)
        if (f > 9)
        {
            sum = sum + (f - 9);
        }
        else
        {
            sum = sum + f;
        }
    }

    //make sum into double to be able to use ceil() (23 / 10 -> 2.3)
    ctrldigit = (float)sum / 10;

    //round up to nearest integer (2.3 -> 3.0)
    //ctrldigit = ceil(ctrldigit);

    //multiply and cast to integer (3.0 -> 30)
    ctrldigit = ctrldigit * 10;

    int final = ((int)ctrldigit) - sum;

    //return ctrldigit which is rounded up sum value (30 - 23 = 7)
    return final;
}

bool isIntegers(char *buf)
{
    int i;
    bool value;
    int len;

    value = true;
    len = strlen(buf) - 1;

    for (i = 0; i < len; i++)
    {
        if (!isdigit(buf[i]))
        {
            value = false;
        }
    }
    return value;
}

bool isPnr(char *buf)
{
    int dd, mm, yy;
    int len;

    len = strlen(buf) - 1;
    //check if 10 digits (YYYYMMDDXXXC)
    if (len != 10)
    {
        return false;
    }

    //get year (transform char to int * 10 (8*10 = 80 + 9 = 89))
    yy = (charToInt(buf[0]) * 10) + charToInt(buf[1]);

    //get month (transform char to int * 10 (1 * 10 = 10 + 2 = 12))
    mm = (charToInt(buf[2]) * 10) + charToInt(buf[3]);

    //get day (transform char to int * 10)
    dd = (charToInt(buf[4]) * 10) + charToInt(buf[5]);

    //https://www.includehelp.com/c-programs/validate-date.aspx

    //check year
    if (yy >= 00 && yy <= 99)
    {
        //check month
        if (mm >= 1 && mm <= 12)
        {
            //check days in relation to months
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
            {
                //Date is valid
            }
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
            {
                //Date is valid
            }
            else if ((dd >= 1 && dd <= 28) && (mm == 2))
            {
                //check for dates in february
                //Date is valid
            }
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
            {
                //check for leap year
                //Date is valid
            }
            else
            {
                printf("Date is invalid.\n");
                return false;
            }
        }
        else
        {
            printf("Month is not valid.\n");
            return false;
        }
    }
    else
    {
        printf("Year is not valid.\n");
        return false;
    }

    if (controlDigit(buf) == charToInt(buf[9]))
    {
        //control digit is correct -> pnr is correct
        return true;
    }
    else
    {
        //control digit not correct
        return false;
    }
}

int charToInt(char c)
{
    return c - '0';
}