#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //Equivalent methods
    char *c_ptr = "ABC";
    char c_arr[] = "ABC";
    char c_arr2[] = {'A', 'B', 'C'};

    //Fills out the rest with zer0s
    char c_arr3[6] = "ABC";

    return 0;
}