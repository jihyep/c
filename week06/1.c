#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
    int i;

    printf("Enter an integer:");
    scanf("%i",&i);

    if (i>0)
        printf("This is positive number.\n");
        else
    		if (i==0)
        	printf("This is 0.\n");
    		else
        		printf("This is negative number.\n");

        return 0;
}