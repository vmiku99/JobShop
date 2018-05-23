#include"jobhead.h"
void GetGreatGene()
{
	int* NormalGeneChain;
	NormalGeneChain=(int*)malloc(sizeof(int)*(ProcedureTotal+1));
	memset(NormalGeneChain,0,(sizeof(int)*(ProcedureTotal+1)));
	int countnum[N+1];
	int j;
    int temp;

        memset(countnum,0,sizeof(countnum));
		memset(NormalGeneChain,0,(sizeof(int)*(ProcedureTotal+1)));
		for(j=1;j<=ProcedureTotal;j++)
		{
            temp=rand()%N+1;
            if(countnum[temp]>=n_num[temp])
            {
                j--;
            }
            else
            {
                NormalGeneChain[j]=temp;
//              printf("%d ",temp);
                countnum[temp]++;
            }
		}
//		printf("\n");
	decode(NormalGeneChain);
	free(NormalGeneChain);
}
int Gene_initialize()
{
	int countnum[N+1];
    int i,j;
    int Arandom; 
    int times=0;
	int Atemp;
    int temp;

    for(i=1;i<chronum;i++)
    {	times++;
        memset(countnum,0,sizeof(countnum));
        for(j=1;j<=ProcedureTotal;j++)
        {
            temp=rand()%N+1;

            if(countnum[temp]>=n_num[temp])
            {
                j--;
                continue;
            }
            else
            {
                ChroOne[i][j]=temp;
//                printf("%d ",temp);
                countnum[temp]++;
            }         
        }
        Arandom=rand()%100+1;
        Atemp=decode(ChroOne[i]);
        if(Atemp>1.2*GreatGeneNum&&Arandom>=GreatGeneNum*50/Atemp)
	    i--;
//        printf("%d\n",i);
    }
//    printf("You try %d times to get %d Chain\n",times,chronum);
    return 0;	 
}

int decode(int* NormalGeneChain)
{
    int *TimeTool=(int*)malloc(sizeof(int)*(N+1));
    int *TimesTool=(int*)malloc(sizeof(int)*(N+1));
	int *TimeMachine=(int*)malloc(sizeof(int)*(M+1));

    int timeStart;
    int temp;
    int maxTime=0;
    int i,j,k;
    memset(TimeMachine,0,sizeof(int)*(M+1));
    memset(TimeTool,0,sizeof(int)*(N+1));
    memset(TimesTool,0,sizeof(int)*(N+1));

    for(j=1;j<=ProcedureTotal;j++)
    {
        temp=NormalGeneChain[j];
       	k=++TimesTool[temp];
	 	timeStart= Max(TimeTool[temp],TimeMachine[Ma[temp][k]]);
		TimeTool[temp]=TimeMachine[Ma[temp][k]]=timeStart+Ti[temp][k];
        maxTime=Max(maxTime,TimeTool[temp]);
    }
	if(GreatGeneNum==0)
	{
			GreatGeneNum=maxTime;
		for(i=1;i<=ProcedureTotal;i++)
   			GreatGeneChain[i]=NormalGeneChain[i];
   			GreatGeneChain[0]=GreatGeneNum=maxTime;
		}
	else
	{
	if(GreatGeneNum>maxTime)
	{		
   		GreatGeneNum=maxTime;
   		GreatGeneChain[0]=GreatGeneNum;
    	for(i=1;i<=ProcedureTotal;i++)
   		GreatGeneChain[i]=NormalGeneChain[i];
   		printf("Change in %d generations\n",generation);
	}}
//	printf("maxTime:%3dGreatGeneNum:%d\n",maxTime,GreatGeneChain[1]);
	//if(GreatGeneNum==0)
	//printf("dd\n");
	NormalGeneChain[0]=maxTime;
	free(TimeMachine);
	free(TimesTool);
	free(TimeTool);
	return maxTime;
}

int Max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
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
