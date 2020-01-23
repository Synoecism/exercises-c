#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //import of boolean type
#include <ctype.h>   // import for isdigit
#include <string.h>
#include <math.h>

#define CTLDIGIT_PLACE 9

void readPersnr(char *person);
int controlDigit(const char *persnr);
int personalNumber[20];
bool isIntegers(char *buf);
bool isPnr(char *buf);
char buf[1024]; // use 1KiB buffer just to be sure

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
    if (!fgets(person, 1024, stdin))
    {
        //check if input is integers
        if (isIntegers(person))
        {
            if (isPnr(person))
            {
                ctrlDigit = controlDigit(person);
                //add controldigit to personnummer
                person[CTLDIGIT_PLACE] = ctrlDigit;

                printf("This is the personnummer: %s\n", person);
            }
            else
            {
                printf("Not a valid personummer.\n");

                //do nothing - return to while
            }
        }
        else
        {
            printf("Not valid input. Please only use integers.\n");
            //do nothing - return to while
        }
        //if buffer is overloaded - do nothing
        printf("Buffer problems.\n");
    }
}

int controlDigit(const char *persnr)
{
    int sum;
    int ctrldigit;
    int i;
    int len = strlen(persnr);
    int multiplier = 1;

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

        //check if value is higher then 9, if true, add to sum as seperate digits (ie 13 -> 1+3)
        if ((persnr[i] * multiplier) > 9)
        {
            sum = sum + ((persnr[i] * multiplier) - 9);
        }
        else
        {
            sum = sum + (persnr[i] * multiplier);
        }
    }

    //make sum into double to be able to use ceil() (23 / 10 -> 2.3)
    ctrldigit = (double)sum / 10;
    //round up to nearest integer (2.3 -> 3.0)
    ctrldigit = ceil(sum);
    //multiply and cast to integer (3.0 -> 30)
    ctrldigit = (int)sum * 10;

    //return ctrldigit which is rounded up sum value (30 - 23 = 7)
    return ctrldigit - sum;
}

bool isIntegers(char *buf)
{
    int i;
    bool value;
    int len;

    value = true;
    len = strlen(buf);

    for (i = 0; i < len; i++)
    {
        if (!isdigit(atoi(&buf[i])))
        {
            value = false;
        }
    }
    return value;
}

bool isPnr(char *buf)
{
    bool value;
    int dd, mm, yy;
    int len;

    len = strlen(buf);
    //check if 9 digits
    if (len != 9)
    {
        return false;
    }

    //https://www.includehelp.com/c-programs/validate-date.aspx

    //get year
    yy = buf[0] + buf[1];

    //get month
    mm = buf[2] + buf[3];

    //get day
    dd = buf[4] + buf[5];

    value = true;

    //check year
    if (yy >= 00 && yy <= 99)
    {
        //check month
        if (mm >= 1 && mm <= 12)
        {
            //check days
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                printf("Date is valid.\n");
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                printf("Date is valid.\n");
            else if ((dd >= 1 && dd <= 28) && (mm == 2))
                printf("Date is valid.\n");
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                printf("Date is valid.\n");
            else
                printf("Day is invalid.\n");
            value = false;
        }
        else
        {
            printf("Month is not valid.\n");
            value = false;
        }
    }
    else
    {
        printf("Year is not valid.\n");
        value = false;
    }
    return value;
}