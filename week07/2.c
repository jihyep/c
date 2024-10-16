#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sumTwo (int a, int b)
{
	return (a+b);
}

int sqare (int n)
{
	return(n*n);
}

int get_max (int x, int y)
{
	if (x>y) return(x);
	else return(y);
}

int main(void) {
	
	int a,b;
	
	printf("Enter the integers:"); 
	scanf("%i %i", &a, &b);
	
	printf("Result - Sum: %i , Square: %i , Max: %i\n", sumTwo(a,b), sqare(a), get_max(a,b));
	
	
	return 0;
}

