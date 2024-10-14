#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int num1, num2;
	char c;
	
	printf("Enter the calculation:");
	scanf("%i %c %i", &num1, &c, &num2);
	
	switch(c){
		case '+':
			printf("= %i\n", num1+num2);
		break;
		
		case '-':
			printf("= %i\n", num1-num2);
		break;
		
		case '*':
			printf("= %i\n", num1*num2);
		break;
		
		case '/':
			printf("= %i\n", num1/num2);
		break;
		
	}
	
	
	return 0;
}
