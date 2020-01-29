/*
File name: exerc_3_3.c (or cpp)
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
#include <time.h>

//#### Constants #####

#define MAX 5
#define UPPER 100
#define LOWER 0

//##### Typedefs #####

typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;

} REGTYPE;

//##### Function declarations  #####

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

//###### Main program #######

int main(int argc, char *argv[])
{
    //initialization
    int nr = 0;
    REGTYPE *curr_position, *head = NULL;

    //Random seed
    srand(time(0));

    //create a random DLL and assign the head as the first node of the list (that is returned from the function)
    head = random_list();

    //set current position in DLL to the position of the head
    curr_position = head;

    //print the DLL positions and values (numbers)
    while (curr_position != NULL)
    {
        printf("\n At index/position: %d. Has value: %d", nr++, curr_position->number);
        curr_position = curr_position->next;
    }

    //Free of allocated memory
    while ((curr_position = head) != NULL)
    {
        head = curr_position->next;
        free(curr_position);
    }

    //End of main
    return 0;
}

// =====  End of main   =====

REGTYPE *random_list(void)
{
    int nr, i;
    i = 0;

    //start loop to create DLL
    for (; i < MAX; i++)
    {
        //create new node (head)
        REGTYPE newNode;

        //create pointer to new node
        REGTYPE *ptr_newNode = &newNode;

        //create random number between 0-100
        nr = (rand() % (UPPER - LOWER + 1)) + LOWER;

        //set value of node number
        ptr_newNode->number = nr;

        //set pointer of node->next

        //set pointer of node->prev
        ptr_newNode->prev = NULL;
    }

    REGTYPE *top, *old, *item;

    //return pointer to new node
    return (top);
}

REGTYPE *add_first(REGTYPE *temp, int data)
{

    // Adds a record first i list and set the field tal to data
}