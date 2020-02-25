#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char str[MAX]; 
    int len = 0;
    int count = 1

    fgets(str, MAX, stdin); 
    len = strlen(str);
    
    for(int i = 0; i < len; i++){
        if(str[i] != ' ' && str[i+1] == ' '){
            count = count+1;
        }
    }

    printf("The number of words in the sentence is: %d \n",count);

    return 0;
    
}