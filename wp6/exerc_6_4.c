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

int program_time;   // The global time, start value 0
int main(){
    // Start up the thread time_count.
    // Start up the thread read_inport.
    While ( program_time < 50){
        //Print out system time every second.
    }
}

void *time_count() {
    while ( program_time < 50){
        // Check system-time ( get_time_ms())
        // Increase program_time by one every second. 
    }
        // exit thread;
}

void *read_inport( ){
    while (program_time<50){
        // Read Inport every 5 second.
        // Simulate this just by print out a text : Reading Inport now)}
        //Exit thread
    }    
} 

// --------Function get_time_ms --------------------
double get_time_ms(){
} 
// ------------End -------------------