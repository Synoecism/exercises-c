#include <stdio.h>
#include<stdlib.h>
int main(){  
    int values[] = { 4, 2, 3, 33, 7};
    int* ptr;
    int no1;
    ptr = values; 
    no1=ptr; // warning: incompatible pointer to integer conversion assigning to 'int' from 'int *'; -- run time
    if(ptr==  values[0])  //warning: comparison between pointer and integer ('int *' and 'int') -- run time
    printf("\n ok 1");
    if(ptr==  &values[0]) 
    printf("\n ok 2");
    if(*ptr== values[0])  
    printf("\n ok 3");
    printf("\n %d\n", ptr[0]); 
    return 0;
}