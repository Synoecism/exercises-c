/*
File name: exerc_x_y.c (or cpp)
Date: 2020-01-19
Group nr 1
Members that contributeto the solutions
Emanuel Dellsén
Niklas Möller
Karl Westgårdh 

Member not present at demonstration time:

Demonstration code: [
<Ass code 1-4> <abc>]Important
No code no exercise points!
*/

#include <stdio.h>
#include <stdlib.h>  //for random generator && atoi
#include <time.h>    //for random generator
#include <stdbool.h> //import of boolean type
#include <ctype.h>   // import for isdigit
#include <string.h>

#define ASCII_NUMBER 48

//https://www.includehelp.com/c-programs/generate-random-numbers-within-a-range.aspx

//needs to declared before main
void start();
bool isNumber();
int getValue();

int main()
{
    bool active = true;
    int counter = 0;
    char consume;
    while (active)
    {
        //check if this is the first game iteration
        if (counter == 0)
        {
            printf("Would you like to play a game? (Type 'Y' to start or any other character to exit program). \n");
        }
        else
        {
            printf("Would you like to play another game? (Type 'Y' to start or any other character to exit program). \n");
        }

        //wait for input
        char ch = getchar();

        switch (ch)
        {
        case 'Y':
            //used to consume \n
            consume = getchar();

            //start game
            start();

            //increment game counter when game is finished
            counter++;
            break;

        //when any other key but "Y" is pressed
        default:
            //used to consume \n
            consume = getchar();
            printf("\n Exiting.. \n");
            active = false;
            break;
        }
    }
    return 0;
}

void start()
{
    //boundaries for the random numbers
    int lower = 1, upper = 100, count = 10;

    //delaring MAX and number guesses
    int max_nr_of_guesses = 10;
    int nr_of_guesses = 1;

    //uses time to seed random generator
    srand(time(0));

    //generate random number
    int answer = (rand() % (upper - lower + 1)) + lower;

    //game continues until guess is equal to random number or max guesses is reached
    for (; nr_of_guesses <= max_nr_of_guesses; nr_of_guesses++)
    {
        //wait for input
        printf("Take a guess... \n");
        char guess[100];
        fgets(guess, 100, stdin);

        // check if guess is digit or not
        if (isNumber(guess))
        {
            int guess_as_int = getValue(guess);

            //check if digit is equal or not to answer
            if (guess_as_int < answer)
            {
                printf("Too low... \n");
            }
            else if (guess_as_int > answer)
            {
                printf("Too high... \n");
            }
            else
            {
                //win scenario
                printf("CONGRATULATIONS!!! You've guessed correctly!!! YOU WIN!!! \n");

                //end game
                nr_of_guesses = max_nr_of_guesses;
            }
        }
        else
        {
            printf("Please enter a valid number \n");
            nr_of_guesses--;
        }
    }
}

bool isNumber(char str[])
{
    //calculate length of char array (len-1 to ignore "enter")
    int len = strlen(str) - 1;
    bool value = true;

    //check if there is any characters that is not digits
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            value = false;
            break;
        }
    }

    return value;
}
int getValue(char str[])
{
    char *ptr;

    //https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
    //calculates value of char array to integer
    int value_of_string = strtol(str,&ptr,10);

    return value_of_string;
}
