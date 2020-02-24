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

bool isEmpty = true;

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

  pthread_mutex_init( &count_mutex, NULL);
pthread_cond_init( &not_empty, NULL);
pthread_cond_init( &not_full, NULL);

    //lock current thread
    pthread_mutex_lock( &count_mutex );

  
    while (1)
    {
        // do something
    }
}

void *put()
{
    while (1)
    {
        pthread_cond_wait(&count_mutex,&not_full);

buffer[inpos] = letter;
        //to increment from a - z
        printf("%c \n", letter);
        letter++;
        if(letter > 'z'){
        letter = 'a';

pthread_cond_signal(&not_empty);
        if(inpos < MAX){
            inpos++;
        } else {
            inpos = 0;
        }
}
        //do something
    }
}

void *fetch()
{


    while (1)
    {

        pthread_cond_wait(&count_mutex, &not_empty);

        char charFound = buffer[outpos];

        printf("char found: %c at index %d \n", charFound, outpos);
        if(outpos < MAX){
        outpos++;
        } else {
            outpos=0;
        }

        pthread_cond_signal(&not_full);
        // do something
    }
}
