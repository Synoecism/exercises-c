#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 101

int main()
{
    char word[MAX];
    int len;
    int j;
    bool value;

    //get input from user
    fgets(word, MAX, stdin);

    //get length of word (ignore enter by -1)
    len = strlen(word) - 1;
    j = len - 1;

    value = true;

    for (int i = 0; i < j; i++)
    {
        if (word[i] != word[j])
        {
            value = false;
            break;
        }
        j--;
    }

    if (value)
    {
        printf("It's a palindrome\n");
    }
    else
    {
        printf("Not a palindrome\n");
    }

    return 0;
}