#include"jobhead.h"
int Max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
void Fitness(int generation)//ÊÊÓ¦¶Èº¯Êı
{	
	int i;
	if(generation%2==1)
		{
			for(i=1;i<chronum;i++)
			{FitFather[i]=ChroOne[i][0]-GreatGeneNum+1;
			FitFather[i]=100000/FitFather[i];
			}
		}
	else 
		{	
			for(i=1;i<chronum;i++)
			{FitFather[i]=ChroTwo[i][0]-GreatGeneNum+1;
			FitFather[i]=100000/FitFather[i];
			}
		}
	for(i=1;i<chronum;i++)
		{
		FitSon[i]=ChroSon[i][0]-GreatGeneNum+1;
		FitSon[i]=100000/FitSon[i];
		}

}
