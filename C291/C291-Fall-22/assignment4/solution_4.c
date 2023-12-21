#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollDice(void);
int a = 0;
int b = 0;
int getSum(int a, int b);
void checkCraps(int score);
char choice = 'n';
int main(void){
srand(time(NULL));
printf("Would you like to play a game of craps? Type y for yes or n for no: ");
scanf("%c",&choice); 
if (choice == 'n'){
	puts("Ok....");
}
else if (choice == 'y'){
puts("dice are rolling...\n");
a = rollDice();
b = rollDice();
int score = getSum(a,b);
printf("Score on dice are : %d and %d\n", a,b);
printf("Sum is: %d\n", score);
checkCraps(score);
}
}
	int rollDice(void){
		int r = 1 + rand() % 6;
		return r; 
	}

	int getSum(int a, int b) {
		int Sum = a + b;
		return Sum;
	}




	void checkCraps(int score){
	if ((score == 7) || (score == 11)){
		printf("%d congratulations, you win!\n", score); 
	} else if ((score == 2) | (score == 3) | (score == 12)) {
		printf("%d sorry, you have lost and the house wins!\n",score); 
	} else if (score == 4 | 5 | 6 | 8 | 9 | 10) {
		printf("Player's point! %d\n",score); 
		printf("Roll %d again before rolling a 7\n",score);
		puts("dice are rolling ....\n");
	       	int c = rollDice();
		int d = rollDice();	
		int sumcd = getSum(c,d);
		while (sumcd != score | 7){
			int c = rollDice();
			int d = rollDice();
			int sumcd = getSum(c,d);
			printf("Score on dice are: %d and %d\n",c,d);
			printf("Sum is: %d\n", getSum(c,d));
			if (sumcd == score){
				puts("consecutive same sum, you won!!\n");
				break;	
			} else if (sumcd == 7){
				puts("7! You lost!\n");
				break;
			} else {
			}
			
		}
	}
	}

