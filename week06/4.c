#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int sum=0;
	int num;
	int a;
	
	printf("Enter a number:");
	scanf("%i", &num);
	
	for (a=1; a<=num; a++)
		sum+=a;
		
		printf("The result is %i\n", sum);
	
	
	
	return 0;
}
