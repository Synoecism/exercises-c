#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define upper_level 77
#define lower_level 109

int main()
{
    char str[MAX];
    int len = 0;
    int KEY = 13;
    char charvalue;
    char encryptvalue;
    char word[MAX];

    fgets(str, MAX, stdin);
    len = strlen(str);

    //header for the program
    printf("V\tA\tEV\tA\t\n");

    //len-1 to not print "enter" which has ascii-value 10
    for (int i = 0; i < len - 1; i++)
    {

        char correct;

        if (i < 1)
        {
            //first letter should be uppercase
            correct = toupper(str[i]);
            if (correct > upper_level)
            {
                encryptvalue = correct + -KEY;
            }
            else
            {
                encryptvalue = correct + KEY;
            }
        }
        else
        {
            //rest of letters in word should be lowercase
            correct = tolower(str[i]);
            if (correct > lower_level)
            {
                encryptvalue = correct + -KEY;
            }
            else
            {
                encryptvalue = correct + KEY;
            }
        }
        word[i] = encryptvalue;
        printf("%c\t%d\t%c\t%d\n", correct, correct, encryptvalue, encryptvalue);
    }
    printf("\n Word is: %s \n",word);
    return 0;
}