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

int main()
{

    int num = 3;
    int *num_ptr = &num;

    printf("value: %d \n", num_ptr[0]);
    printf("value: %c \n", num_ptr[0]);
    printf("value: %x \n", num_ptr[0]);
    printf("value: %p \n", num_ptr[0]);

    printf("next: %d \n", num_ptr[1]);
    printf("next: %c \n", num_ptr[1]);
    printf("next: %x \n", num_ptr[1]);
    printf("next:  %p \n", num_ptr[1]);

    printf("next next: %d \n", num_ptr[2]);
    printf("next next: %c \n", num_ptr[2]);
    printf("next next: %x \n", num_ptr[2]);
    printf("next next: %p \n", num_ptr[2]);

    return 0;
}