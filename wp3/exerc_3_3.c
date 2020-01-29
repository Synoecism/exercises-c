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

    //****** CREATE A RANDOMIZED DOUBLY LINKED LIST ******* //

    printf("\n Creating a randomized doubly linked list \n");

    //Random seed
    srand(time(0));

    //create a random DLL and assign the head as the first node of the list (that is returned from the function)
    head = random_list();

    //set current position in DLL to the position of the head
    curr_position = head;

    //print the DLL positions and values (numbers)
    while (curr_position != NULL)
    {
        printf("\n At index: %d. Has value: %d", nr++, curr_position->number);
        curr_position = curr_position->next;
    }

    //****** END ******* //

    //****** ADD A VALUE TO FIRST POSITION ******* //

    printf("\n Adding a value to first position in doubly linked list \n");

    //add a value in the first position (use current head as input)
    head = add_first(head, 100);

    //set current position in DLL to the position of the head
    curr_position = head;

    //reset counter
    nr = 0;

    //print the updated DLL positions and values (numbers)
    while (curr_position != NULL)
    {
        printf("\n At index: %d. Has value: %d", nr++, curr_position->number);
        curr_position = curr_position->next;
    }
    printf("\n");
    //****** END ******* //

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

        //use malloc to be able access new memory AKA memory mgmt
        newNode = (struct q *)malloc(sizeof(REGTYPE));

        //create pointer to new node
        ptr_newNode = newNode;

        //create random number between 0-100
        nr = (rand() % (UPPER - LOWER + 1)) + LOWER;

        //set value of node number
        ptr_newNode->number = nr;

        if (i == 0)
        {
            top = ptr_newNode;
        }
        else
        {
            old->next = ptr_newNode;
        }

        //Set next of new node to NULL
        ptr_newNode->next = NULL;

        //Set the pointer of prev of new node to the old node
        ptr_newNode->prev = old;

        //Change the pointer old to point to the newly created node
        old = ptr_newNode;
    }

    //return pointer to new node
    return (top);
}

REGTYPE *add_first(REGTYPE *temp, int data)
{
    //initalization
    struct q *newNode;
    REGTYPE *ptr_newNode;

    //use malloc to be able access new memory AKA memory mgmt
    newNode = (struct q *)malloc(sizeof(REGTYPE));

    //create pointer to new node
    ptr_newNode = newNode;

    //set value of newNode
    newNode->number = data;

    //set prev of current head to new node
    temp->prev = ptr_newNode;

    //set next of new node to current head
    ptr_newNode->next = temp;

    //set prev of new node to NULL
    ptr_newNode->prev = NULL;

    //return what will be the new head
    return ptr_newNode;
}