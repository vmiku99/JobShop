#include"jobhead.h"
void Gene_decode()
{
	int *ptr=(int *)malloc(sizeof(int)*chronum);
	int *pptr=(int *)malloc(sizeof(int)*chronum);
	int a,b;
	int i;
	memset(ptr,0,sizeof(int)*chronum);
	memset(pptr,0,sizeof(int)*chronum);
	if(generation%2==1)
	{
	
		for(a=1;a<=chronum-1;a++)
		{
//	for(i=0;i<=ProcedureTotal;i++)
//		printf("%d ",ChroOne[a][i]);
//		printf("generation%d\n",generation);
			for(b=1;ptr[b]!=0&&ChroOne[a][0]!=ptr[b]&&b<=chronum-1;b++);
			if(ChroOne[a][0]==ptr[b])
	
			{
				pptr[b]++;
			}
			else {
			ptr[b]=ChroOne[a][0];
			pptr[b]++;
		}}
	}
	else
	{
		for(a=1;a<=chronum-1;a++)
		{
			for(b=1;ptr[b]!=0&&ChroTwo[a][0]!=ptr[b]&&b<=chronum-1;b++);
			if(ChroTwo[a][0]==ptr[b])
	
			{
				pptr[b]++;
			}
			else {
			ptr[b]=ChroTwo[a][0];
			pptr[b]++;
		}}		
		
	}
	for(a=1;ptr[a]!=0&&a<chronum;a++)
	{printf("Time:%5d Times:%3d  %d\n",ptr[a],pptr[a],a);}

	free(pptr);
	free(ptr);


}
