/*
File name: exerc_2_2.c (or cpp)
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
#include <stdlib.h> //for random generator && atoi
#include <time.h>   //for random generator

#define UPPER 99
#define LOWER 1
#define MAX 101

int main()
{
    int array[MAX];
    int n;

    //get array size in indicies (not byte size)
    n = sizeof(array) / sizeof(array[0]);

    //uses time to seed random generator
    srand(time(0));

    //loop over the array and fill the array with random values
    for (int i = 0; i < n; i++)
    {
        array[i] = (rand() % (UPPER - LOWER + 1)) + LOWER;
    }

    //lots of prints
    printf("\n The value of the label array (address) is: %pn \n", &array);
    printf("First integer in the array is (array[0]): %d \n", array[0]);
    printf("The size of an integer (number of bytes - array[0]) is: %lu \n", sizeof(array[0]));
    printf("The size (length) of the whole array is: %d \n", n);
    printf("The size (bytes) of the whole array is: %lu \n", sizeof(array));

    for (int i = 0; i < n; i++)
    {
        //Creating a pointer that points to the address where the value in the index of the array is stored
        int *pt = &array[i];

        //Printing the value that the pointer points to (use asterix)
        printf("Integer value of index %d: %d \n", i, *pt);

        //Printing the value (with double format) that the pointer points to (use asterix)
        printf("Double value of index %d: %4.2lf \n", i, (double)*pt);
    }

    return 0;
}