#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int combination(int n, int r)
{
	return factorial(n)/(factorial(n-r)*factorial(r));
}

int factorial(int n)
{
	int i;
	int res =1;
	for (i=1; i<=n; i++)
		res*=i;
	return res;
}

int get_integer()
{
	int input;	
	
	printf("Enter the value: ");
	scanf("%i", &input);
	return input;
}

int main(void)
{
	int n, r;
	
	n= get_integer();
	r= get_integer();
	
	combination(n,r);
	printf("The result of C (%i, %i) is %i\n", n, r, combination(n, r));
	
	return 0;
}
