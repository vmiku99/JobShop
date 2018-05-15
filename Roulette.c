#include"jobhead.h"
void Roulette(int generation)
{
	int FitAll=0;
	int i,j;
	for(i=1;i<chronum;i++)
		FitAll+=FitFather[i]+FitSon[i];

	int temp;
	int foot;

	foot+=temp;
	foot%=FitAll;
	int key=0;
	int	finish;

	for(finish=1;i<chronum;i++)
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
						for(i=0;i<=ProcedureTotal;i++)
						ChroTwo[i]=ChroOne[i];
					else
						for(i=1;i<=ProcedureTotal;i++)
						ChroOne[i]=ChroTwo[i];
				}
			}
		for(i=1;i<chronum&&key==0;i++)
			{if(foot>FitSon[i])
				{foot-=FitSon[i];}
			else
				{
					key=1;
					if(generation%2==1)
						for(i=0;i<=ProcedureTotal;i++)
						ChroTwo[i]=ChroSon[i];
					else
						for(i=1;i<=ProcedureTotal;i++)
						ChroOne[i]=ChroSon[i];
				}
			}
	}

}
