#include <stdio.h>

int main(void)
{
	char c;
	int i;
	
	printf("enter a character: ");
	scanf("%c", &c);
	
	i = c;
	
	printf("the next character of %c(%i) is %c(%i)", c, i, c+1, i+1);
	
	return 0;
}
