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

    //init thread
    pthread_t t;
    pthread_t t2;

    // create thread for put
    pthread_create(&t, NULL, put, NULL);

    // create thread for fetch
    pthread_create(&t2, NULL, fetch, NULL);

    //Run in infinity
    while (1)
    {
        pthread_mutex_lock(&count_mutex);


        if (count == 2)
        {

            //confirm main thread
            puts("Main is executing");

            //reset count
            count = 0;
        }
        pthread_mutex_unlock(&count_mutex);
    }
}

void *put()
{

    while (1)
    {
        //lock access to global variables
        pthread_mutex_lock(&count_mutex);

        if (count == 0)
        {
            //set buffer index to letter
            buffer[inpos] = letter;

            //confirm store of letter
            puts("Buffer store");

            //increment letter
            letter++;

            //if end of alphabet, start at 'a'
            if (letter > 'z')
            {
                letter = 'a';
            }

            //when inpos is 10, set to 0
            if (inpos < MAX-1)
            {
                inpos++;
            }
            else
            {
                inpos = 0;
            }

            //increment count
            count++;
        }

        //send signal to other thread
        pthread_cond_signal(&not_empty);

        //unlock access to global variables
        pthread_mutex_unlock(&count_mutex);
    }
}

void *fetch()
{

    while (1)
    {
        //lock access to global variables
        pthread_mutex_lock(&count_mutex);

        //wait for signal from other thread
        pthread_cond_wait(&not_empty, &count_mutex);

        if (count == 1)
        {
            //get the character at index
            char charFound = buffer[outpos];

            //confirm fetched charachter
            printf("Buffer output: %c\n", charFound);

            //if outpos = 10, start over at 0 needs to be minus 1
            if (outpos < MAX-1)
            {
                outpos++;
            }
            else
            {
                outpos = 0;
            }

            //increment count
            count++;

            //send conditional signal
            pthread_cond_signal(&not_full);

            //unlock the mutex
            pthread_mutex_unlock(&count_mutex);
        }
    }
}
