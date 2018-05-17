#include"jobhead.h"
int DeNormalGene(int* NormalGeneChain)
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
