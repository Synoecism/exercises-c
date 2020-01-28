/*
File name: exerc_3_1.c (or cpp)
Date: 2020-01-28
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
#include <ctype.h> // import for isdigit
#include <string.h>
#include <stdbool.h>

#define X 'x'
#define Y 'y'

enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

char arrayOfInput[21];
char userInput[1024];
int xValueToPass = 0;
int yValueToPass = 0;

//REF: https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum

const char *directions[] = {"N", "O", "S", "W"};
ROBOT myRobot;
ROBOT *ptr_myRobot;

void move();
void turn();
int start();
int stop();
void getCoordinateInput(char *arrayOfInput, char coordinate);
bool isValid(char *userInput);
int checkRange(int inputValue);
void getDirectionsInput(char *arrayOfInput);
void passValue(ROBOT *DEF, int xpos, int ypos, enum DIRECTION dir);

int main()
{
    ROBOT myRobot = {3, 0, N};

    ptr_myRobot = &myRobot;
            printf("I am the Robot. Please give me instructions or shut me off...\n");

    do
    {

        getCoordinateInput(arrayOfInput, X);
        getCoordinateInput(arrayOfInput, Y);
        //clears the array
        memset(arrayOfInput, 0, sizeof(arrayOfInput));
        getDirectionsInput(arrayOfInput);
        start(arrayOfInput);
        //When all instructions are executed robot stops and the program prints out the new robot positionfor the robot
        stop();
        printf("I have more energy to spend. I want to walk more. Please provide new instructions below: \n");

    } while (1);
    //change while(1) to something else later
    return 0;
}

void getDirectionsInput(char *arrayOfInput)
{
    bool valid;
    int i, counter, arrayLength;
    arrayLength = strlen(arrayOfInput);
    counter = 0;

    do
    {
        valid = false;
        printf("Provide the directions I shall walk. 'm' to make me move \n and 't' to make me turn! \n");

        if (!fgets(userInput, 1024, stdin)) //reads input with fgets(), usidng standard input stdin. Checks we don't overflow buffer
        {
            // reading input failed, give up:
            return;
        }
        if (userInput[0] != '\n')
        {
            for (i = 0; i < strlen(userInput) - 1; i++)
            {
                char inputChar = userInput[i];

                if ('m' == inputChar || 't' == inputChar)
                {
                    arrayOfInput[arrayLength + i] = userInput[i];
                }
                else
                {
                    counter++;
                }
            }
            printf("Thanks to MY logic we removed %d faulty inputs! \n", counter);

            if (arrayLength < strlen(arrayOfInput) - 1)
            {
                printf("I will start to walk\n");
                valid = true;
            }
        }
        printf("Please enter some directions for me. I need to walk!\n");
        counter = 0;

    } while (!valid);
}
void getCoordinateInput(char *arrayOfInput, char coordinate)
{
    bool valid;

    do
    {
        valid = false;
        printf("Provide the %c coordinate between 0-99: \n", coordinate);
        if (!fgets(userInput, 1024, stdin)) //reads input with fgets(), usidng standard input stdin. Checks we don't overflow buffer
        {
            // reading input failed, give up:
            return;
        }
        if (isValid(userInput))
        {
            valid = true;

            if (coordinate == 'x')
            {

                strncat(arrayOfInput, userInput, 2);
                xValueToPass = atoi(arrayOfInput);
            }
            else
            {
                strncat(arrayOfInput, userInput, 2);
                yValueToPass = atoi(userInput);
                passValue(ptr_myRobot, xValueToPass, yValueToPass, N);
            }
        }
        else
        {
            printf("Do not forget to only enter integers between 0 and 99! Try again\n");
        }
    } while (!valid);
}

bool isValid(char *userInput)
{

    int i;
    int arrayLength;

    arrayLength = strlen(userInput) - 1;
    for (i = 0; i < arrayLength; i++)
    {
        if (isdigit(userInput[i]) == 1)
        {
            //it is a digit
        }
        else
        {
            return false;
        }
    }

    if (checkRange(atoi(userInput)) != 0)
    {
        //true for one digit
    }
    else
    {
        return false;
    }

    return true;
}

int checkRange(int inputValue)
{
    if (inputValue >= 0 && inputValue <= 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int start(char *arrayOfInput)
{
    int i;

    for (i = 0; i < strlen(arrayOfInput); i++)
    {
        if (arrayOfInput[i] == 'm')
        {
            move();
        }
        else if (arrayOfInput[i] == 't')
        {
            turn();
        }
        else
        {
            printf("We have found something faulty");
        }
    }

    return 0;
}

int stop()
{

    printf("I have stopped and my position is now: (%d,%d). Heading: %s \n",ptr_myRobot->xpos, ptr_myRobot->ypos, directions[ptr_myRobot->dir]);
    return 0;
}

void move()
{
    int presentDirection = ptr_myRobot->dir;
    switch (presentDirection)
    {
    case 0:
        ptr_myRobot->ypos++;
        break;
    case 1:
        ptr_myRobot->xpos++;
        break;
    case 2:
        ptr_myRobot->ypos--;
        break;
    case 3:
        ptr_myRobot->xpos--;
        break;
    }
}

void turn()
{
    int presentDirection = ptr_myRobot->dir;
    presentDirection++;
    //this is magic
    ptr_myRobot->dir = presentDirection % 4;
}

void passValue(ROBOT *myRobot, int xpos, int ypos, enum DIRECTION dir)
{

    myRobot->xpos = xpos;
    myRobot->ypos = ypos;
    myRobot->dir = dir;
}
