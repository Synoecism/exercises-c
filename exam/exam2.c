#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int num = 1; // (1) init variable with value
    int *num_ptr = &num; // (2) create pointer
    printf("%d \n",*num_ptr); // (3) print value of pointer 
    printf("%p \n",num_ptr); // (4) print address of pointer
    printf("%p \n",&num_ptr); // (5) print address of pointer value
    printf("%p \n",&num); // (6) print address of value, same as (4)
    printf("%d \n", num); // (7) print value of variable, same as (3)

}