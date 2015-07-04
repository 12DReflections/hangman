#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(){

	char guessWords[][16] = {
		"green",
		"yellow",
		"purple",
		"window",
		"linux",
		"apple",
	};
	
	//index for random word
	int randomIndex = rand() % 6;
	int loopIndex = 0;
	
	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);
	int letterGuessed[8] = {0,0,0,0,0,0,0,0};
	
	int quit = 0;
	
	loopIndex = 0;
	
	char guess[16];
	
	printf("guessWords: %s randomIndex : %d lengthOfWord: %d\n",
		guessWords[randomIndex], randomIndex, lengthOfWord);
	
	//While our correct guesses are less than word length
	while (numCorrect < lengthOfWord){
		
		printf("\nEnter a guess letter: ");
		fgets(guess, 16, stdin);
		
		if( strncmp(guess, "quit" , 4 ) == 0 ) {
			quit = 1;
			break;
		}
	}
	
	if( quit == 1 ) {
		printf("\nThe user quit early\n");
	}
	
	
	return 0;

}
