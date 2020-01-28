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
#include <stdlib.h>
#include <ctype.h> // import for isdigit
#include <string.h>
#include <stdbool.h>

#define MAX 100

int search_number(int number, int tab[], int size);
int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
void sort(int number, int tab[]);
void printArray(int number, int tab[]);
int charToInt(char c);
char userInput[MAX];

int main()
{
    //prompt user
    printf("Please input an integer below\n");

    //get input from user
    fgets(userInput, 100, stdin);

    //validate user input (if atoi returns 0; its' NaN)
    int inputNumber = atoi(userInput);

    //continue if inputNumber is numbers/digits
    if (inputNumber != 0)
    {
        //calculate length of array
        int arrayLength = sizeof(test) / sizeof(test[0]);

        //search in predefined array for the number of user input
        search_number(inputNumber, test, arrayLength);

        //sort the predefined array
        sort(arrayLength, test);
    }

    return 0;
}

int search_number(int number, int tab[], int size)
{
    int i;

    //iterate over the array and look for the user specified number
    for (i = 0; i < size; i++)
    {
        if (tab[i] == number)
        {
            printf("Found it on: %d\n", i);
            //return index of position of found number
            return i;
        }
    }
    //if number doesnt exist, return -1
    return -1;
}

void sort(int number, int tab[])
{

    int i, j, smallestValue = 0, arrayLength, positionToSwap = 0, temp = 0;

    //print the values of the array before sorting has begun
    printArray(number, tab);
    printf(" = array before the sorting is done \n");

    for (i = 0; i < number; i++)
    {
        j = i;
        smallestValue = tab[i];
        positionToSwap = i;

        for (; j < number; j++)
        {
            if (tab[j] < smallestValue)
            {
                smallestValue = tab[j];
                positionToSwap = j;
            }
        }
        //swop values that has been found
        temp = tab[i];
        tab[i] = smallestValue;
        tab[positionToSwap] = temp;
    }

    //print array after sorting
    printArray(number, tab);
    printf(" = array after the sorting is done \n");
}

void printArray(int number, int tab[])
{
    int i, arrayLength;
    for (i = 0; i < number; i++)
    {
        printf("%d, ", tab[i]);
    }
}
