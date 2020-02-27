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

    // create thread for put
    pthread_create(&t, NULL, put, NULL);

    // create thread for fetch
    pthread_create(&t, NULL, fetch, NULL);

    //Run in infinity
    while (1)
    {
        //wait for a signal
        pthread_cond_wait(&not_full, &count_mutex);

        //confirm main thread
        puts("Main is executing");
    }
}

void *put()
{

    while (1)
    {
        // if count == 0, buffer is empty
        if(count == 0){
            //wait for trigger from other function
        pthread_cond_wait(&not_full, &count_mutex);
        }

        //lock the access to global variables
        pthread_mutex_lock(&count_mutex);

        //set buffer index to letter
        buffer[inpos] = letter;

        //confirm store of letter
        puts("Buffer store");

        //increment count
        count++;

        //unlock the access to global variables
        pthread_mutex_unlock(&count_mutex);

        //trigger conditional signal, listened to by other thread
        pthread_cond_signal(&not_empty);

        //increment letter
        letter++;

        //if end of alphabet, start at 'a'
        if (letter > 'z')
        {
            letter = 'a';
        }

        //when inpos is 10, set to 0
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

    while (1)
    {
        //if count not zero, then there are values in the buffer
        if(count != 0){
            //wait for conditional signal from other thread
            pthread_cond_wait(&not_empty, &count_mutex);

        }

        

        //get the character at index
        char charFound = buffer[outpos];

        //confirm fetched charachter
        printf("Buffer output: %c\n", charFound);

        //send conditional signal
        pthread_cond_signal(&not_full);

        //if outpos = 10, start over at 0
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
