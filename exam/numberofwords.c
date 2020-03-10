/*
 * C Program to Count Number of Words in a given Text Or Sentence
 */
#include <stdio.h>
#include <string.h>

int numberOfWords(char *str)
{
    int count = 0;
    while(*str){
        if(*str == 0x20){
            count++;
        }
        str++;
    }

    return count+1;
}

int main()
{
    char s[200] = "hello manne kalle";
    int count = numberOfWords(s);
    printf("Number of words in given string are: %d\n", count);

    return 0;
}