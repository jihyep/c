#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int answer=50;
	int i;
	int num=0;
	
	
	do
	{
		printf("Guess a number:");
		scanf("%i", &i);	
		num	++;
		
		
		if (i>answer)
			printf("High!\n");
		else if(i<answer)
			printf("Low!\n");
	
		
	} while(i!=answer);
		printf("Congratulation! Trials: %i\n", num);
	
	return 0;
}
