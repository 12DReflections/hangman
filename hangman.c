#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(){
	
	srand(time(NULL));
	
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
	
	// Letter indexes are changed from 0 to 1 when letters are correctly guessed
	//				     0 1 2 3 4
	//				     a p p  l e
	int letterGuessed[8] = {0,0,0,0,0,0,0,0};
	
	int quit = 0;
	
	loopIndex = 0;
	
	char guess[16];
	char letterEntered;
	
	
	printf("guessWords: %s randomIndex : %d lengthOfWord: %d\n",
		guessWords[randomIndex], randomIndex, lengthOfWord);
	
	//Game Loop
	while (numCorrect < lengthOfWord){
		
		printf("Number correct so far: %d\n", numCorrect); 
		printf("\nEnter a guess letter: ");
		fgets(guess, 16, stdin);
		
		if( strncmp(guess, "quit" , 4 ) == 0 ) {
			quit = 1;
			break;
		}
		
		letterEntered = guess[0];
		
		printf("\nLetter Entered: %c\n", letterEntered);
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++){
			
			if( letterGuessed[loopIndex] == 1 ){
				continue;
			}
		
			if( letterEntered == guessWords[randomIndex][loopIndex]){
				letterGuessed[loopIndex] = 1;
				numCorrect++;
			}
		}
		
	} //while loop
	
	if( quit == 1 ) {
		printf("\nThe user quit early\n");
	}
	
	
	return 0;

}
