//Hangman Game programmed by Julian Wise following 'Programming in C with Ease'

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
	
	int randomIndex = rand() % 6; //Translate the random number into the count of options we have
	int loopIndex = 0; //the index where each of the words is
	
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
		
		printf("\n\nNew Turn....\nHangman Word: ");
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++ ){
			
			if(letterGuessed[loopIndex] == 1) {
				printf("%c", guessWords[randomIndex][loopIndex]);
			} else {
				printf("-");
			}
		}
		
		
		printf("\n\nNumber correct so far: %d\n", numCorrect); 
		printf("\nEnter a guess letter: ");
		fgets(guess, 16, stdin);
		
		if( strncmp(guess, "quit" , 4 ) == 0 ) {
			quit = 1;
			break;
		}
		
		letterEntered = guess[0];
		
		printf("\nLetter Entered: %c\n", letterEntered);
		
		oldCorrect = numCorrect; //Guess total comparison
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++){
			
			if( letterGuessed[loopIndex] == 1 ){ 
				continue;
			}
		
			if( letterEntered == guessWords[randomIndex][loopIndex]){
				letterGuessed[loopIndex] = 1; //change in our array to 1, for guessed correctly
				numCorrect++;
			}
		}
		
		//Test whether we guessed correctly.
		if( oldCorrect == numCorrect){
			numLives--;
			printf("Sorry, wrong guess, \nLives = %d \n",numLives);
			
			if( numLives == 0 ) {
				break;
			}
			
		} else {
			printf("\nYou guessed correctly!\n");
		}
		
	} //while loop
	
	if( quit == 1 ) {
		printf("\nThe user quit early\n");
	} else if(numLives == 0) {
		printf( "Sorry you lose, the word was: %s\n",guessWords[randomIndex]);
	} else{
		printf( "\n\nYou win you champ!\n");
	}
	
	
	return 0;

}
