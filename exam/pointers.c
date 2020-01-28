#include <stdio.h>

//pointer instructions

int main()
{
    //initialiazion of integer
    int num;

    //declaration of interger
    num = 10;

    //initialiazion of pointer to integer
    int *ptr;

    //declaration of pointer to integer to the address of the integer (set the address of the pointer)
    ptr = &num;

    //get value where the pointer is pointing to:
    printf("\n %d", *ptr);

    //get the address where the pointer is pointing to:
    printf("\n %p", ptr);

    //set value where the pointer is pointing to:
    *ptr = 20;
    printf("\n %d", *ptr);

    //change the address of the pointer:
    int num2;
    num2 = 30;
    ptr = &num2;

    //print new value after change of address
    printf("\n New value of pointer: %d", *ptr);

    //print new address after change of address
    printf("\n New address of pointer: %p", ptr);

    //work with strings
    char c;
    c = 'a';

    //always initalise char pointers with value NULL;
    char *ptr_c = NULL;

    //set address of char pointer
    ptr_c = &c;

    //set value of char by use of pointer
    *ptr_c = 'b';

    //get value of char by use of pointer
    printf("\n %c", *ptr_c);

    //double pointer usage
    int num3;
    num3 = 3;

    int *ptr_num3 = &num3;

    //set value of dptr to address of ptr
    int **dptr_num3 = &ptr_num3;

    //get value of ptr address
    printf("\n %d", *ptr_num3);

    //get value of dptr address
    printf("\n %d", **dptr_num3);

    //set value by use of dptr
    **dptr_num3 = 5;

    //get new value of dptr address
    printf("\n %d", **dptr_num3);

    //get value by reference
    printf("\n %d", num3);

    //get address of ptr
    printf("\n %p", ptr_num3);

    //get address of dptr
    printf("\n %p", dptr_num3);

    //get value of dptr (which is the address of the ptr)
    printf("\n %p", *dptr_num3);

    //End of program
    printf("\n");

    return 0;
}