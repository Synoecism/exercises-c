#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 101

int main()
{
    char word[MAX];

    //get input from user
    fgets(word, MAX, stdin);

    //get length of word (ignore enter by -1)
    int len = strlen(word) - 1;
    int j = len - 1;

    bool value = true;

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