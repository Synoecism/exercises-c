#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int main(void)
{
    char str1[MAX], *pos;
    int year;

    puts("\n Please write your family name : ");
    fgets(str1, MAX, stdin);
    pos = strchr(str1, '\n');
    if (pos != NULL)
    {
        *pos = '\0';
    }
    puts("\n Please write your age : ");
    scanf("%d", &year);
    printf("\n Your name is %s and you are %d years old ", str1, year);
    return 0;
}