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
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <signal.h>

#define ML13_Status 0x0B10
#define ML13_Control 0x0B00
#define read 0x0B01

// 0x28
#define door_is_closed_and_someone_approaching 40 
// 0x88
#define door_is_closing_and_someone_approaching 136 
// 0x0C
#define door_is_open_and_someone_approaching 12
// 0x48
#define door_is_opening_and_someone_approaching 72
// 0x10
#define door_is_now_open 16
// 0x20
#define door_is_now_closed 32

#define open_the_door 0x01
#define close_the_door 0x10
#define reset_control 0x00

// this is bit 3 to 5
#define sensor_bits 0xf0

// was previously read_control but that made no sense what so ever
#define read_status *((char *)ML13_Status)
#define set_control(x) *((char *)ML13_Control)=x

int whatIsTheStatus;
int RISING = 1;
void attachInterrupt(void *param, unsigned char address);

void ML13_interrupt();
void setup();
void startDelay();

int main () {

//init setup of program
setup();

while(1){
    //run the program
}

return 0;
}

void setup(){

    //should be a macro
    //activate listener to listen for changes (0 -> 1) on bit 3,4,5
    attachInterrupt(ML13_interrupt, sensor_bits);

}

// __interrupt does not work.

void ML13_interrupt(){

// read the status register
whatIsTheStatus = read_status;

switch(whatIsTheStatus){

    case door_is_now_open:
        puts("motor should be turned off");
        startDelay();
        set_control(close_the_door);
    case door_is_now_closed:
        puts("motor should be turned off");
        //do nothing
    case door_is_closed_and_someone_approaching:
        set_control(open_the_door);
    case door_is_open_and_someone_approaching:
        //this basically resets the delay (see assumptions in startDelay method)
        startDelay();
        set_control(close_the_door);
    case door_is_closing_and_someone_approaching:
        set_control(open_the_door);
    case door_is_opening_and_someone_approaching:
        //do nothing - continue opening the door
    break;
}

    

}

void startDelay(){
// we assume that this function will be interrupted and 
// a "break" will occur when and interrupt request occurs

//delay implemented as a for loop, as steted in intructions. Takes about 8 seconds to execute.
   int c, d;
   for (c = 1; c <= 70000; c++){
       for (d = 1; d <= 70000; d++){
       }
    }
       
}

