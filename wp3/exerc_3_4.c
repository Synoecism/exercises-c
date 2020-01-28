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

#include <stdlib.h>#include <stdio.h>
// -----Typedefs -------//
typedef struct
{
    char firstname[20];
    char famnamne[20];
    char pers_number[13];
    yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void);

// Reads in a person record.void
write_new_file(PERSON *inrecord);

//Creates a file and write a first recordvoid
printfile(void);

// print out all persons in the filevoid
search_by_firstname(char *name);

// print out person if in list void
append_file(PERSON *inrecord);
// appends a new person to the file

int main(void)
{
    PERSON ppost;
    return (0);
}    