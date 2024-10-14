#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(void)
{
	int num=0;
	char c;
	
	printf("Input a string: ");
	
	while((c=getchar())!='\n')
	
		if (c>=48&&c<=57)
			num++;

	printf("The number of digits is %i\n", num);		
	
	return 0;
 } 
