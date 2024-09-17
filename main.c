#define _CRT_SECURE_NO_WARNINGS
#define RANDMIN 1
#define RANDMAX 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNum();
int comp_RPS(int num);
int user_RPS();
void game(int comp, int user, int round, int *point);

int main() {
    srand(time(NULL));
	int tries = 1;
	int score = 0;
	int run = 0;
    int cont;
    int compChoice;
    int plyrChoice;

    while (run == 0){
        compChoice = randNum();
        plyrChoice = user_RPS();

        game(compChoice, plyrChoice, tries, &score);

        printf("\nPlay again?\n0: continue\n1: quit\n\n");
        scanf("%d", &cont);
        if(cont != 0){
            run++;
        }
        else {
            tries++;
        }
        printf("\e[1;1H\e[2J");
    }


	return 0;
}

// generates and returns a random number in range of 1 - 3 inclusive
int randNum() {
	int randNum = rand() % (RANDMAX + 1 - RANDMIN) + RANDMIN;
	return randNum;
}


// Accepts a single character as user choice -> returns: player
int user_RPS() {
	int player = 0;

	printf("Rock Paper or Scissors?");
	printf("\n\nEnter \n1\tRock \n2\tPaper \n3\tScissors\n\n");

	scanf("%d", &player);

	return player;
}

// function handling generated and IO values.
void game(int comp, int user, int round, int *point) {
char choices[3] = {'R', 'P', 'S'};

if(comp == user)
    {
    printf("\nTie!\n");
    printf("Player: %c\nComputer: %c", choices[user-1], choices[comp-1]);
    printf("\nRound: %d\n", round);
    printf("\nScore: %d\n", *point);
    }

    else if ( (user == 3 && comp == 2) || (user == 2 && comp == 1) || (user == 1 && comp == 3) )
    {
        printf("\nYou Win!");
        printf("\nPlayer: %c\nComputer: %c", choices[user-1], choices[comp-1]);
        *point += 1;
        printf("\nRound: %d", round);
        printf("\nScore: %d\n", *point);
    }

    else
    {
        printf("\nYou lost!\n");

        if (*point == 0)
        {
            printf("Player: %c\nComputer: %c", choices[user-1], choices[comp-1]);
            printf("\nRound: %d", round);
            printf("\nScore: 0\n");
        }
        else
        {
            printf("Player: %c\nComputer: %c", choices[user-1], choices[comp-1]);
            printf("\nYou lost a point...\n");
            *point -= 1;
            printf("\nRound: %d", round);
            printf("\nScore:\t%d\n", *point);
        }
    }
}
