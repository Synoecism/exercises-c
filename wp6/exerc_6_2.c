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

// Program for exercise 6.2alt in DIT632
// Version 2020-02-12
// File : sortandfind_20.c
// **************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *sortArray(void *param);
void *findValue(void *param);

int main()
{
    time_t t;
    pthread_t tid_1;
    pthread_attr_t attr_1;
    pthread_t tid_2;
    pthread_attr_t attr_2;
    pthread_t tid_3;
    pthread_attr_t attr_3;

    srand((unsigned)time(&t));
    pthread_attr_init(&attr_1);

    printf("Enter max value\n");
    scanf("%d", &max_value);

    pthread_create(&tid_1, &attr_1, runner, NULL);
    pthread_join(tid_1, NULL);
    pthread_attr_init(&attr_2);
    pthread_create(&tid_2, &attr_2, sortArray, NULL);
    pthread_join(tid_2, NULL);
    pthread_attr_init(&attr_3);
    pthread_create(&tid_3, &attr_3, findValue, NULL);
    pthread_join(tid_3, NULL);

    return 0;
}

void *runner(void *param)
{
    puts("Executing runner 1. Filling the array with random integers");

    int c = 0, n = 0;

    for (c = 0; c < num_elems; c++)
    {
        for (n = 0; n < 1000; n++)
            ; // To delay a bit
        array[c] = rand() % max_value;
    }

    pthread_exit(0);
}

void *sortArray(void *param)
{

    puts("Executing runner 2. Sorting this messy array");

    int c, d, swap;

    for (c = 0; c < num_elems; c++)
    {
        for (d = 0; d < num_elems - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    pthread_exit(0);
}

void *findValue(void *param)
{

    int search;
    printf("Enter value to find\n");
    scanf("%d", &search);
    puts("Executing runner 3. Finding value");

    int first = 0;
    int last = num_elems - 1;
    int middle = (first + last) / 2;
    int n;
    for (n = 0; n < num_elems; n++)
    {
        //printf("\n %d", array[n]);
    }

    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search)
        {
            printf("\n %d found at location %d.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("\n Not found! %d is not present in the list.\n", search);

    pthread_exit(0);
}
