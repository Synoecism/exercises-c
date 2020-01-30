/*
File name: exerc_2_6.c (or cpp)
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

#define MAX 5
int que[MAX];

void initQue(int list[], int max);
int input(int list[], int number, int max);
int output(int list[], int max);
void test();

int main()
{
    //initialization of the queue
    initQue(que, MAX);

    //just a test function to test the functions of the queue
    test();

    return 0;
}

void initQue(int list[], int max)
{
    int i, vacancyRepresentation = -1;

    for (i = 0; i < max; i++)
    {
        list[i] = vacancyRepresentation;
    }
}

int input(int list[], int number, int max)
{

    // - 1 to make sure we dont get index out of bounds
    int i = max - 1;
    int empty = -1;

    // check if queue is full, if true then return 0
    if (empty != list[i])
    {
        return 0;
    }
    else
    {
        for (; i >= 0; i--)
        {

            if (list[i - 1] != empty)
            {
                list[i] = number;
                break;
            }
        }

        return 1;
    }
}
int output(int list[], int max)
{
    int i, value;
    if (list[0] == -1)
    {
        return 0;
    }

    //get value of first in queue
    value = list[0];

    for (i = 0; i < max - 1; i++)
    {
        list[i] = list[i + 1];
    }
    list[max - 1] = -1;

    return value;
}

void test()
{
    input(que, 3, MAX);

    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");
    input(que, 4, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    input(que, 7, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    input(que, 8, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }

    printf("\n");

    input(que, 8, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }

    printf("\n");
    printf("If queue is full return 0. The returned value is %d", input(que, 8, MAX));
    printf("\n");

    output(que, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    output(que, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    output(que, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    output(que, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    output(que, MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", que[i]);
    }
    printf("\n");

    printf("If queue is empty return 0. The returned value is %d\n", output(que, MAX));
}