#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX 7

int *lotto_row(void);
void sorting(int *tab);

void sorting(int *tab)
{
    int current_min = 0;
    int temp = 0;
    int min_index = 0;

    for (int i = 0; i < MAX-1; i++)
    {
        current_min = tab[i];
        for (int j = i; j < MAX; j++)
        {
            if (tab[j] < current_min)
            {
                current_min = tab[j];
                min_index = j;
            }
        }
        temp = tab[i];
        tab[i] = current_min;
        tab[min_index] = temp;
    }

    // print the array
    for (int i = 0; i < MAX; i++)
    {
        printf("Tab index %d has value %d \n", i, tab[i]);
    }
}

int *lotto_row(void)
{
    int *ptr = (int *)malloc(MAX * sizeof(int));
    int num = 0;
    bool exists = false;
    srand(time(0));

    for (int i = 0; i < MAX; i++)
    {
        num = (rand() % (35 - 1 + 1)) + 1;
        for (int j = 0; j < i; j++)
        {
            if (num == ptr[j])
            {
                exists = true;
                return NULL;
            }
        }
        if (!exists)
        {
            ptr[i] = num;
        }
    }
    return ptr;
}

int main(void)
{

    int *ptr = lotto_row();
    if (ptr != NULL)
    {
        for (int i = 0; i < MAX; i++)
        {
            printf("%d \n", ptr[i]);
        }
    }
    else
    {
        puts("shit failed");
    }

    sorting(ptr);
}