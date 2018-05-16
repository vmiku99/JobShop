#include"jobhead.h"
void Championships(int generation)
{
	int temp;
	int finish;
	int i;
	int tempchamgrade;
	int tempchamnum;
	int tempgrade;
	if(generation%2==1)
	{	
		for(finish=1;finish<chronum;finish++)
		{	
			tempchamgrade=0;
			tempchamnum=0;
			for(i=1;i<chronum;i++)
			{
				temp=rand()%(2*(chronum-1))+1;
				if(temp>=chronum)
					tempgrade=ChroSon[temp-chronum+1][0];
				else 
					tempgrade=ChroOne[temp][0];
				if(tempchamnum==0)
				{	tempchamnum=temp;
					tempchamgrade=tempgrade;	
				}
				else if(tempgrade<tempchamgrade)
				{
					tempchamnum=temp;
					tempchamgrade=tempgrade;
				}
			}

				if(temp>=chronum)
					{for(i=0;i<=ProcedureTotal;i++)
						ChroTwo[finish][i]=ChroSon[temp-chronum+1][i];}
				else
					{for(i=0;i<=ProcedureTotal;i++)
						ChroTwo[finish][i]=ChroOne[temp][i];}
		}
	}
	else 
	{	
		for(finish=1;finish<chronum;finish++)
		{	
			tempchamgrade=0;
			tempchamnum=0;
			for(i=1;i<chronum;i++)
			{
				temp=rand()%(2*(chronum-1))+1;
				if(temp>=chronum)
					tempgrade=ChroSon[temp-chronum+1][0];
				else 
					tempgrade=ChroOne[temp][0];
				if(tempchamnum==0)
				{	tempchamnum=temp;
					tempchamgrade=tempgrade;	
				}
				else if(tempgrade<tempchamgrade)
				{
					tempchamnum=temp;
					tempchamgrade=tempgrade;
				}
			}

				if(temp>=chronum)
					{for(i=0;i<=ProcedureTotal;i++)
						ChroOne[finish][i]=ChroSon[temp-chronum+1][i];}
				else
					{for(i=0;i<=ProcedureTotal;i++)
						ChroOne[finish][i]=ChroTwo[temp][i];}
		}		
	}
	return ;
}
