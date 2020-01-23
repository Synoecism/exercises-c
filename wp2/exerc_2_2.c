#include <stdio.h>
#include <stdlib.h> //for random generator && atoi
#include <time.h>   //for random generator

#define UPPER 99
#define LOWER 1
#define MAX 101

int main()
{

    int array[MAX];

    //get array size in indicies (not byte size)
    int n = sizeof(array) / sizeof(array[0]);

    //uses time to seed random generator
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        array[i] = (rand() % (UPPER - LOWER + 1)) + LOWER;
    }

    printf("\n The value of the label array (address) is: %pn \n", &array);
    printf("First integer in the array is (array[0]): %d \n", array[0]);
    printf("The size of an integer (number of bytes - array[0]) is: %lu \n", sizeof(array[0]));
    printf("The size (length) of the whole array is: %d \n", n);
    printf("The size (bytes) of the whole array is: %lu \n", sizeof(array));

    for (int i = 0; i < n; i++)
    {
        printf("Integer value of index %d: %d \n", i, array[i]);
        printf("Double value of index %d: %lf \n", i, (double) array[i]);
    }

    return 0;
}