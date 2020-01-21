//Write a program that reads in an integer number between 1 and 5 from the keyboard and prints out 
//one of existing five sentences on the console depending on what number was entered.
//The program continues to ask for a new number and exits if number isn´t in the interval 1 to 5.


#include <stdio.h>

int main(void) {
   
    int num; 

do{

    printf("Enter an integer between 1 - 5:\n"); 
    scanf("%d", &num); //Scan the integer and locate at the address-of number
  
    if(num == 1){
        printf("One is the amount of noses at your face\n");
    }else if(num == 2){
        printf("Two is the amount of hands you have\n");
    }else if(num == 3){
        printf("Three... Cant find anything on your body that is three\n");
    }else if(num == 4){
        printf("Four would be your toes - exept the big one\n");
    }else if(num == 5){
        printf("Five and you have the fingers at your hand\n");
    }

}while ((num < 6) && (num > 0));

}

