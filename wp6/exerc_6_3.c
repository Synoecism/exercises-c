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

#define ML13_Status 0x0B10
#define ML13_Control 0x0B00 

void *doorSpaceSensorRunner(void *param);
void *doorLockSensorRunner(void *param);

void main () {

bool doesTheDoorHaveElectricity = true;

setup();



while(doesTheDoorHaveElectricity){

// if (pingFromDoorSpaceSensor)
// set doorState to opening
// start timer and countdown 7 seconds
// when timer reach 7 seconds 
// if(pingFromDoorLockSensor)
// set doorState to open
// start new counter to close door
// if(pingFromDoorSpaceSensor)
// reset timer to 7 seconds
// when new counter reaches 7 seconds
// set doorState to closing
// if (pingFromDoorSpaceSensor)
// set doorState to opening
// else 
// if(pingFromDoorLockSensor && new timer == 0 seconds)
// set doorState to closed
}

}

void setup(){



pthread_t doorSpaceSensorThread_id;
pthread_attr_t doorSpaceSensorThreadAttr;

pthread_t doorLockSensorThread_id;
pthread_attr_t doorLockSensorThreadAttr;


pthread_attr_init(&doorSpaceSensorThreadAttr);
pthread_create(&doorSpaceSensorThread_id, &doorSpaceSensorThreadAttr, doorSpaceSensorRunner, NULL);
pthread_attr_init(&doorLockSensorThreadAttr);
pthread_create(&doorLockSensorThread_id, &doorLockSensorThreadAttr, doorLockSensorRunner, NULL);

// set door state to closed

}

void *doorSpaceSensorRunner(void *param){



}

void *doorLockSensorRunner(void *param){



}