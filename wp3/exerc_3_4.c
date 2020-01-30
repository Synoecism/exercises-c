/*
File name: exerc_3_4.c (or cpp)
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// -----Typedefs -------//
typedef struct
{
    char firstname[20];
    char famnamne[20];
    char pers_number[13];
} PERSON;

#define MAX 10 //1 Kb to not overflow
char buffer[MAX];
char *ptr_buffer = buffer;

FILE *file;
char *filename = "persons.bin";

// Function declaration (to be extend)
PERSON input_record(void); // Reads in a person record

void write_new_file(PERSON *inrecord); //Creates a file and write a first record

void printfile(void); // print out all persons in the file

void search_by_firstname(char *name); // print out person if in list

void append_file(PERSON *inrecord); // appends a new person to the file

void print_menu();

void getInput(char *ptr_buffer);

int main(void)
{
    PERSON ppost;
    PERSON *ptr_ppost = &ppost;

    //create a dummy struct
    PERSON dummy = {.firstname = "John",.famnamne = "Doe",.pers_number = "9001019999"};

    //assign the pointer to the address of the dummy
    ptr_ppost = &dummy;

    puts("Hello and welcome! \n");

MENU:
    print_menu();

    //get user input of choice to direct from menu
    getInput(ptr_buffer);
    int choice = atoi(ptr_buffer);

    switch (choice)
    {
    case 1:
        write_new_file(ptr_ppost);
        break;
    case 2:
        input_record();
        break;
    case 3:
        puts("Enter the firstname of the person you want to search for:");
        getInput(ptr_buffer);
        //search_by_firstname();
        break;
    case 4:
        printfile();
        break;
    case 5:
        puts("Goodbye! :)");
        exit(0);
    default:
        puts("Please enter a valid number between 1 - 5.");
    }

    goto MENU;

    return (0);
}

void print_menu()
{
    puts("Please pick one of the options:\n");
    puts("1 Create a new and delete the old file");
    puts("2 Add a new person to the file");
    puts("3 Search for a person in the file");
    puts("4 Print out all in the file");
    puts("5 Exit the program.\n");
}

void getInput(char *ptr_buffer)
{
    fgets(ptr_buffer, MAX, stdin);
}

PERSON input_record(void)
{
    PERSON myperson = {};
    return myperson;
};

void write_new_file(PERSON *inrecord)
{
    //Solution from the book: An Introduction to C Programming for Java Programmers by Mark Handley

    /* open the file for writing. w means create a empty file for writing */
    file = fopen(filename, "w+");

    if (file == NULL)
    {
        fprintf(stderr, "File %s could not be openednn", filename);
        exit(1);
    }

    /* write to the file */
    fprintf(file, "%s %s %s",inrecord->firstname,inrecord->famnamne,inrecord->pers_number);
    /* close the file */
    fclose(file);
};

void printfile(void)
{

    puts("In Print file");
    //Solution from the book: An Introduction to C Programming for Java Programmers by Mark Handley
    /* open the file for writing. R means opening the file for reading. The file must exist*/
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File %s could not be openednn", filename);
        exit(1);
    }
    /* loop while reading a line at a time from the file and printing */
    while (1)
    {
        char buffer[80];
        fgets(buffer, 80, file);
        /* if it’s the end of file, break out of this loop */
        if (feof(file))
            break;
        printf("%s", buffer);
    }
    /* close the file */
    fclose(file);
};

void search_by_firstname(char *name)
{

    puts("In serach by firstname");
};

void append_file(PERSON *inrecord)
{

    puts("In append_file");
};