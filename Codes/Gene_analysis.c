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
	int timeStart=-1;
    int temp;
    int maxTime=0;
    int i,j,k;
    int c,d;
    memset(TimeMachine,0,sizeof(int)*(M+1));
    memset(TimeTool,0,sizeof(int)*(N+1));
    memset(TimesTool,0,sizeof(int)*(N+1));
    int MaTimeStart[M+1][N+1];
    int MaTimeStop[M+1][N+1];
	for(i=0;i<=M;i++)
	{	
    memset(MaTimeStart[i],0,sizeof(int)*(N+1));
    memset(MaTimeStop[i],0,sizeof(int)*(N+1));
	}
    int ma,a;
	for(j=1;j<=ProcedureTotal;j++)
	{	
		temp=NormalGeneChain[j];
   		k=++TimesTool[temp];
		ma=Ma[temp][k];

	   	for(a=1;MaTimeStop[ma][a]!=0&&timeStart==-1;a++)
	   		{if(MaTimeStart[ma][a+1]-MaTimeStop[ma][a]>=Ti[temp][k]&&(MaTimeStop[ma][a]>=TimeTool[temp]||MaTimeStart[ma][a+1]-Ti[temp][k]>=TimeTool[temp]))
	   			timeStart=MaTimeStop[ma][a];
	   		}		
	   	if(timeStart==-1)
 		{	
		 	for(a=1;MaTimeStop[ma][a]!=0;a++)
		 	;
			timeStart=Max(TimeTool[temp],TimeMachine[ma]);
			MaTimeStart[ma][a]=timeStart;
 			TimeMachine[ma]=TimeTool[temp]=MaTimeStop[ma][a]=timeStart+Ti[temp][k];
 			maxTime=Max(maxTime,MaTimeStop[temp][a]);
 		}
 		else if(MaTimeStop[ma][a]>=TimeTool[temp]) 
 		{
 			MaTimeStop[ma][a]+=Ti[temp][k];
 			TimeTool[temp]=MaTimeStop[ma][a];
 		}
 		else 
 		{	
 			TimeTool[temp]=MaTimeStart[ma][a+1];
 			MaTimeStart[ma][a+1]-=Ti[temp][k];
		 }
    	timeStart=-1;
	}
	free(TimeMachine);
	free(TimesTool);
	free(TimeTool);

	for(c=1;c<=M;c++)
	for(d=1;MaTimeStop[c][d]!=0;d++)
	maxTime=Max(maxTime,MaTimeStop[c][d]);
			
	if(GreatGeneNum==0)
	{	
		printf("%d to %d",GreatGeneNum,maxTime);
			GreatGeneNum=maxTime;
		for(i=1;i<=ProcedureTotal;i++)
			GreatGeneChain[i]=NormalGeneChain[i];
		GreatGeneChain[0]=GreatGeneNum=maxTime;
		printf("Change in %d generations\n",generation);
	}
	else
	{
	if(GreatGeneNum>maxTime)
	{	printf("%d to %d",GreatGeneNum,maxTime);
   		GreatGeneNum=maxTime;
   		GreatGeneChain[0]=GreatGeneNum;
    	for(i=1;i<=ProcedureTotal;i++)
   		GreatGeneChain[i]=NormalGeneChain[i];
   		printf("Change in %d generations\n",generation);
	}}
	NormalGeneChain[0]=maxTime;
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
