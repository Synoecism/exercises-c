#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX 7

int *lotto_row(void);

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
    } else {
        puts("shit failed");
    }
}