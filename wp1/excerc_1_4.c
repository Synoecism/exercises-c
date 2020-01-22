/* You should develop a very simple game in which the computer creates a random integer number between 1..100. 
The user then tries to guess the number. The program should work as specified below:

- The computer creates a random number
- The user guess the number
- The computer respond by printing one of :

You have guessed xx times and your guess is correct. Or
Your guess is to low or to high.

- If wrong the user is asked for a new guess, this will continue until the guess is right or the number
of guesses exceeds the value MAX_NUMBER.
- After end of one round the user is asked for a new round or to finish.
The program should only except guessed numbers in the range of 1 …100.
An option, but not a demand, is to secure that the program not fail (crashes) if a user by
accident put in any character instead of a number. */

//Input checking from http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html

#include <stdio.h>
#include <stdlib.h>

int randomNumber;
int guessedNumber;
int numberOfGuesses;
int MAX_NUMBER = 10;
char c;
char buf[1024]; // use 1KiB buffer just to be sure

int main(void) {

do{

numberOfGuesses = 0; //Resetting in the beginning of every game
randomNumber = rand() % 100 + 1; //Generates the random number between 1 - 100

printf("Welcome to the guessing game! \nTry guessing the random number. \n");

do{

    //The loop prevents undefined behaviour if the input is a char. Also prevents buffer overflow.
    //Loops two times if you play again... Why?
    do
    {
        printf("Enter a number between 1 - 100: \n");
        if (!fgets(buf, 1024, stdin)) //reads input with fgets(), usidng standard input stdin. Checks we don't overflow buffer
        {
            // reading input failed, give up:
            return 1;
        }

        guessedNumber = atoi(buf); // Using the buffer and atoi ("Anything TO Integer")
    } while ((guessedNumber > 100) || (guessedNumber < 1)); // Returns 0 if the input was not a valid number. Checks the interval 1 - 100,

numberOfGuesses++; //Increment the number of guesses

if(guessedNumber < randomNumber){
    printf("Your guess is to low\n");
}
else if(guessedNumber > randomNumber){
        printf("Your guess is to high\n");
}

//Did not work to put this logic into the while loop for some reason
if(numberOfGuesses == MAX_NUMBER){
    printf("Sorry... You guessed more than 10 times\n");
    break;
}

}while(randomNumber != guessedNumber);

if(randomNumber == guessedNumber){
printf("Congratulations! You have guessed %i times and your guess is correct! \n", numberOfGuesses);
}

printf("Press ENTER to EXIT or any key followed by ENTER to play again\n");

c = getchar();

}while(c!='\n');

}
