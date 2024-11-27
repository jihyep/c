#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define STUDENTNUM 4
struct student{
	int ID;
	int score;
};

void main(void){
	struct student s[STUDENTNUM];
	
	int i;
	int max;
	int maxID;
	float sum;
	for(i=0;i<STUDENTNUM;i++)
	{
		printf("Input the ID:");
		scanf("%d", &s[i].ID);
		
		printf("Input the score:");
		scanf("%d", &s[i].score);
		
		sum+=s[i].score;  
	}
	
	max =s[0].score;
	for(i=1;i<STUDENTNUM;i++)
	{
		if(max<s[i].score){
			max=s[i].score;
			maxID = s[i].ID;}
	}
	
	printf("The average of the score: %f\n", sum/STUDENTNUM);
	printf("The highest score - ID: %d, score: %d\n", maxID, max);
	
}
