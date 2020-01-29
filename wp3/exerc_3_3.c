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

    printf("\n Printing the HEADS (aka TOP) number in main(): %d \n", head->number);
    printf("\n Printing the next next from head in main(): %d \n", head->next->next->prev->prev->number);


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

    REGTYPE *top, *old, *item;

    //Init with NULL to set values in loop
    old = NULL;
    top = NULL;

    REGTYPE *ptr_newNode;
        

    //start loop to create DLL
    for (; i < MAX; i++)
    {

        //create new node
        struct q *newNode;
        newNode = (struct q *)malloc( sizeof(REGTYPE) );
        printf("Address of newNode is: %x \n", &newNode);

        //create pointer to new node
        ptr_newNode = newNode;
        printf("Address of ptr_newNode is: %x \n", ptr_newNode);


        //create random number between 0-100
        nr = (rand() % (UPPER - LOWER + 1)) + LOWER;

        printf("The random number generated at iteration %d is:  %d \n", i, nr);

        //set value of node number
        ptr_newNode->number = nr;

        if(i == 0){
            top = ptr_newNode;    
        }else{
            old->next = ptr_newNode;
        }

        printf("The value of old after else statement is: %p \n", old);

        //set next to NULL
        ptr_newNode->next = NULL;

        ptr_newNode->prev = old; //Poiting to old as prev

        old = ptr_newNode;

        printf("The adress of ptr_newnode is: %p \n", ptr_newNode);
        printf("The adress of old is: %p \n", old);
        printf("The ptr_newnode - PREV: %p, NEXT: %p, NUM: %d \n", ptr_newNode->prev, ptr_newNode->next, ptr_newNode->number);
        puts("\n");
    
    }

    //return pointer to new node
    return (top);
}

REGTYPE *add_first(REGTYPE *temp, int data)
{

    // Adds a record first i list and set the field tal to data
}