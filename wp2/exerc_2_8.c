/*
 *  File    : nim.c 
 *  Program : Nim game
 *  Author  : ...
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

int humanChoice;
char buf[1024];

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner(int player);

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle(int player);

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
    int pile,    /* This is how many coins we have */
        player,  /* Who is playing? */
        n_coins; /* Number of coins taken */

    srand(time(0)); /* Setup random */

    printf("V�lkommen till NIM by ...");

    pile = MAX_COINS; /* Set start values (= init) */
    player = HUMAN;

    /* 
   *  Program main loop 
   */
    while (true)
    {

        printf("Det ligger %d  mynt i h�gen\n", pile);

        if (player == HUMAN)
        {
            n_coins = human_choice(pile);
        }
        else
        {
            n_coins = computer_choice(pile);
            printf("- Jag tog %d\n", n_coins);
        }
        pile -= n_coins;
        player = toggle(player);

        if (pile <= 1)
        {
            break;
        }
    }
    /*
   * end main loop
   */

    write_winner(player);

    printf("Avslutat\n");

    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/

void clear_stdin()
{
    while (getchar() != '\n')
    {
        ;
    }
}

int human_choice(int pile)
{
    //Input checking from http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
    //The loop prevents undefined behaviour if the input is a char. Also prevents buffer overflow.
    do
    {
        printf("Enter a choice between 1 - 3: \n");
        if (!fgets(buf, 1024, stdin)) //reads input with fgets(), usidng standard input stdin. Checks we don't overflow buffer
        {
            // reading input failed, give up:
            return 1;
        }

        humanChoice = atoi(buf); // Using the buffer and atoi ("Anything TO Integer")
<<<<<<< HEAD
    } while (humanChoice > 3 || humanChoice < 1); // Returns 0 if the input was not a valid number


=======
    } while (humanChoice != 0);  // Returns 0 if the input was not a valid number
>>>>>>> 2a94f598e8318af703e54b95d28c6e88e3613523

    return 0;
}

int computer_choice(int pile)
{
    return 0;
}

void write_winner(int player)
{
}

int play_again()
{
    return 0;
}

int toggle(int player)
{
<<<<<<< HEAD

}

=======
    return 0;
}
>>>>>>> 2a94f598e8318af703e54b95d28c6e88e3613523
