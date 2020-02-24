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

// Skeleton for exercise nr 5 in WP 6 course DIT632.
// File skeleton_exerc_6_5.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

//**  Global buffer and corresponding counters. ** //

// the starting letter
char letter = 'a';
//buffer size
#define MAX 10
unsigned short count = 0;
// circular buffer
char buffer[MAX];
// index for next character to be put in buffer (put)
int inpos = 0;
// index for next character to be read ( fetch )
int outpos = 0;

// thread functions
void *put();
void *fetch();

int main()
{
    int i;
    puts("Main thread starting...");

    //init thread
    pthread_t t;

    //init of conditions and locks
    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);

    // create thread for put
    pthread_create(&t, NULL, put, NULL);

    // create thread for fetch
    pthread_create(&t, NULL, fetch, NULL);

    while (1)
    {
        // do something
    }
}

void *put()
{

    pthread_mutex_lock(&count_mutex);
    while (1)
    {
        pthread_cond_wait(&count_mutex, &not_full);
        printf("inpos is : %d \t", inpos);
        printf("char before %c \n", letter);

        buffer[inpos] = letter;
                pthread_cond_signal(&not_empty);

        pthread_mutex_unlock(&count_mutex);
        letter++;
        if (letter > 'z')
        {
            letter = 'a';
        }

        if (inpos < MAX - 1)
        {
            inpos++;
        }
        else
        {

            inpos = 0;
        }

    }
}

void *fetch()
{
    pthread_mutex_lock(&count_mutex);

    while (1)
    {

        pthread_cond_wait(&count_mutex, &not_empty);
        char charFound = buffer[outpos];
        pthread_cond_signal(&not_full);

        pthread_mutex_unlock(&count_mutex);
        printf("char found: %c at index %d \n", charFound, outpos);

        if (outpos < MAX - 1)
        {
            outpos++;
        }
        else
        {
            outpos = 0;
        }
    }
}
