#include<stdio.h>

int main()
{
    char name[100];
    printf("What is your name?: ");
    fgets(name,10,stdin);
    printf("Hello mister, %s.n",name);
    return 0;
}