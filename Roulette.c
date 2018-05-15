#include"jobhead.h"
void Roulette(int generation)
{
	int FitAll=0;
	int i,j;
	for(i=1;i<chronum;i++)
		FitAll+=FitFather[i]+FitSon[i];

	int temp;
	int foot;
	int key=0;
	int	finish;

	for(finish=1;finish<chronum;finish++)
	{	
		temp=rand()%FitAll+1;
		foot=rand()%FitAll+1;
		key=0;
		foot+=temp;
		foot%=FitAll;
		for(i=1;i<chronum&&key==0;i++)
			{if(foot>FitFather[i])
				{foot-=FitFather[i];}
			else
				{
					key=1;
					if(generation%2==1)
						for(j=0;j<=ProcedureTotal;j++)
						ChroTwo[finish][j]=ChroOne[i][j];
					else
						for(i=1;i<=ProcedureTotal;i++)
						ChroOne[finish][j]=ChroTwo[i][j];
				}
			}
		for(i=1;i<chronum&&key==0;i++)
			{if(foot>FitSon[i])
				{foot-=FitSon[i];}
			else
				{
					key=1;
					if(generation%2==1)
						for(j=0;j<=ProcedureTotal;j++)
						ChroTwo[finish][j]=ChroOne[i][j];
					else
						for(i=1;i<=ProcedureTotal;i++)
						ChroOne[finish][j]=ChroTwo[i][j];
				}
			}
	}

}
