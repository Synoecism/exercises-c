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

void *time_count();
void *read_inport();

double get_time_ms(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
    }


int program_time;   // The global time, start value 0
int main(){
    // Start up the thread time_count.

program_time = 0;
    pthread_t time_count_id;
    pthread_attr_t time_count_attr;

    pthread_attr_init(&time_count_attr);
    pthread_create(&time_count_id,&time_count_attr,time_count, &program_time);
    
    // Start up the thread read_inport.

    pthread_t read_inport_id;
    pthread_attr_t read_inport_attr;

    pthread_attr_init(&read_inport_attr);
    pthread_create(&read_inport_id,&read_inport_attr,read_inport, &program_time);

    while ( program_time < 50){
        //Print out system time every second.

        printf("Time is: %d\n", program_time);
    }
}

void *time_count() {
    double startTime = get_time_ms();

    while ( program_time < 50){
        // Check system-time ( get_time_ms())
        double currentTime = get_time_ms();

        if(startTime - currentTime > 1000){
 printf("get time is: %f\n", currentTime);
        // Increase program_time by one every second. 
        program_time++;
        startTime = currentTime;
        }
       
    }
        // exit thread;
        pthread_exit(0);

}

void *read_inport( ){
    while (program_time<50){
        // Read Inport every 5 second.
        // Simulate this just by print out a text : Reading Inport now)}
        //printf("Reading inport now...");
    }    
        //Exit thread
        pthread_exit(0);

} 


// ------------End -------------------