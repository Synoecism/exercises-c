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
// why int number???????? ASK ON THURSDAY
void sort(int number, int tab[]);
void printArray(int number, int tab[]);
int charToInt(char c);
char userInput[MAX];

int main()
{

    printf("Please input an integer below\n");
    fgets(userInput, 100, stdin);
    int inputNumber = atoi(userInput);
    int arrayLength = sizeof(test) / sizeof(test[0]);

    search_number(inputNumber, test, arrayLength);

    sort(arrayLength, test);
    return 0;
}

int search_number(int number, int tab[], int size)
{

    int i;

    for (i = 0; i < size; i++)
    {
        if (tab[i] == number)
        {
            printf("Found it on: %d\n", i);
            return i;
        }
    }
    return -1;
}

void sort(int number, int tab[])
{

    int i, j, smallestValue = 0, arrayLength, positionToSwap = 0, temp= 0;
    printArray(number, tab);
        printf(" = array before the sorting is done \n");

    for (i = 0; i < number; i++)
    {
       j = i;
        smallestValue = tab[i];
        positionToSwap = i;

        for (; j < number ; j++)
        {
            if (tab[j] < smallestValue)
            {
                smallestValue = tab[j];
                positionToSwap = j;
            }
        }
        //swop
        temp = tab[i];
        tab[i] = smallestValue;
        tab[positionToSwap] = temp;
    }
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
