#include <stdio.h>
#include <stdlib.h>

int personalNumber;
char buf[1024]; // use 1KiB buffer just to be sure

//Input checking from http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html

int main(void) {

    //The loop prevents undefined behaviour if the input is a char. Also prevents buffer overflow.
    do
    {
        printf("Enter a personal number: \n");
        if (!fgets(buf, 1024, stdin)) //reads input with fgets(), usidng standard input stdin. Checks we don't overflow buffer
        {
            // reading input failed, give up:
            return 1;
        }

        personalNumber = atoi(buf); // Using the buffer and atoi ("Anything TO Integer")
    } while (personalNumber != 0); // Returns 0 if the input was not a number

}