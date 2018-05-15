#include"jobhead.h"
int DeNormalGene(int* NormalGeneChain)
{
    int *TimeTool=(int*)malloc(sizeof(int)*(N+1));
    int *TimesTool=(int*)malloc(sizeof(int)*(N+1));
	int *TimeMachine=(int*)malloc(sizeof(int)*(M+1));

    int timeStart;
    int temp;
    int maxTime=0;
    int j,k;
    memset(TimeMachine,0,sizeof(int)*(M+1));
    memset(TimeTool,0,sizeof(int)*(N+1));
    memset(TimesTool,0,sizeof(int)*(N+1));

    for(j=1;j<=ProcedureTotal;j++)
    {   //printf("hhhhhhhhhh\n");
        temp=NormalGeneChain[j];
       	 
		k=++TimesTool[temp];
		//k=TimesTool[temp];
		//if(k>10)
		//printf("\t\t%d %d\n",TimesTool[temp],temp);
	 	timeStart= Max(TimeTool[temp],TimeMachine[Ma[temp][k]]);
		TimeTool[temp]=TimeMachine[Ma[temp][k]]=timeStart+Ti[temp][k];
        maxTime=Max(maxTime,TimeTool[temp]);
     //   printf("%d\n",maxTime);
    }
//printf("hhhhhhhhhh\n");
	if(GreatGeneNum==0)
		GreatGeneNum=maxTime;
	else 
	{
	//printf("%d %d %d\n",GreatGeneNum,maxTime,GreatGeneNum>maxTime);
	if(GreatGeneNum>maxTime)
	{//	printf("hhhhhhhhhh\n");
		GreatGeneNum=maxTime;
    	for(j=1;j<=ProcedureTotal;j++)
   			GreatGeneChain[j]=NormalGeneChain[j];
	}}
	
//	free(TimeMachine);
//	free(TimesTool);
//	free(TimeTool);
	return maxTime;
}
