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
                continue;
            }
            else
            {
                NormalGeneChain[j]=temp;
//              printf("%d ",temp);
                countnum[temp]++;
            }
		}
//		printf("\n");
	DeNormalGene(NormalGeneChain);
	free(NormalGeneChain);
}
