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

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

#define SECOND 1000
#define FIVE_SECONDS 5000

double get_time_ms();
void *time_count(void *p_void_ptr);
void *read_inport(void *p_void_ptr);
int program_time;

double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

void *time_count(void *p_void_ptr)
{
    //localize time variables
    double start_time;
    double current_time;

    //get start time
    start_time = get_time_ms();

    //localize pointer
    int *program_time_ptr = (int *)p_void_ptr;

    //run while program_time is less than 50
    while (*program_time_ptr < 50)
    {
        //get current time
        current_time = get_time_ms();

        //check if timer is 1 second
        if ((current_time - start_time) >= SECOND)
        {
            //increment program time by 1
            ++*program_time_ptr;

            //reset start time to current time
            start_time = current_time;
        }
    }

    /* the function must return something - NULL will do */
    return NULL;
}

void *read_inport(void *p_void_ptr)
{
    //localize time variables
    double start_time;
    double current_time;

    //get start time
    start_time = get_time_ms();

    //localize pointer
    int *program_time_ptr = (int *)p_void_ptr;

    //run while program_time is less than 50
    while (*program_time_ptr < 50)
    {
        //get current time
        current_time = get_time_ms();

        //check if timer is five seconds
        if ((current_time - start_time) >= FIVE_SECONDS)
        {
            //print as per instruction
            puts("Reading value now");

            //reset start time to current time
            start_time = current_time;
        }
    }

    /* the function must return something - NULL will do */
    return NULL;
}

int main()
{
    //localize time variables
    double start_time;
    double current_time;

    // init of variables
    program_time = 0;
    pthread_t time_count_id;
    pthread_t read_inport_id;

    //thread creation
    if (pthread_create(&time_count_id, NULL, time_count, &program_time))
    {
        perror("ERROR");
    }
    if (pthread_create(&read_inport_id, NULL, read_inport, &program_time))
    {
        perror("ERROR");
    }

    //get start time
    start_time = get_time_ms();

    //run til program_time is exhausted
    while (program_time < 50)
    {
        //get current time
        current_time = get_time_ms();

        //check if timer is 1 second
        if ((current_time - start_time) >= SECOND)
        {
            //print time
            printf("Time is: %d\n", program_time);

            //reset start time to current time
            start_time = current_time;
        }
    }
    
    //thread joining
    if (pthread_join(time_count_id, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    if (pthread_join(read_inport_id, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    
}
