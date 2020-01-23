#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20
#define MINNUMBER 0

// ------Function declaration   ----------
void create_random(int *tab);

// Use pointer to fill the table

void count_frequency(int *tab, int *freq);

// Use pointer

void draw_histogram(int *freq);

//  Use pointer
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
    srand(time(0));
    for (i = 0; i < MAX; i++)
    {
        tab[i] = (rand() % (MAXNUMBER - MINNUMBER + 1)) + MINNUMBER;
    }
}

void count_frequency(int *tab, int *freq)
{
    int i, j, frequencyCounter = 0;
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