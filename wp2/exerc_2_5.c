/*
File name: exerc_2_5.c (or cpp)
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
#include <time.h>

#define MAX 100
#define MAXNUMBER 20
#define MINNUMBER 0

// ------Function declaration   ----------
void create_random(int *tab);

void count_frequency(int *tab, int *freq);

void draw_histogram(int *freq);

int main(void)
{
    int table[MAX], n, i;
    int frequency[MAXNUMBER];
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);
}

void create_random(int *tab)
{
    int i;

    //seed random using time
    srand(time(0));

    //loop over the array and add random values to the indicies
    for (i = 0; i < MAX; i++)
    {
        tab[i] = (rand() % (MAXNUMBER - MINNUMBER + 1)) + MINNUMBER;
    }
}

void count_frequency(int *tab, int *freq)
{
    int i, j, frequencyCounter = 0;

    //loop over the array and count the number of occurences of any value that exists
    for (i = 0; i < MAXNUMBER; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (tab[j] == i)
            {
                frequencyCounter++;
            }
        }
        freq[i] = frequencyCounter;
        frequencyCounter = 0;
    }
}

void draw_histogram(int *freq)
{

    int i, j, k;
    char histogramSign[MAXNUMBER];

    for (i = 0; i < MAXNUMBER; i++)
    {
        j = freq[i];
        if (j > 0)
        {
            printf("%d\t", i);
            for (k = 0; k <= j; k++)
            {
                printf("x");
            }
            printf("\n");
        }
    }
}