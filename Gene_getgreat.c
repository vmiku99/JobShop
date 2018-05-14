#include"jobhead.h"
void GetGreatGene()
{
	int NormalGenenumber=0;
	int* NormalGeneChain;
	NormalGeneChain=(int*)malloc(sizeof(int)*(ProcedureTotal+1));
	memset(NormalGeneChain,0,sizeof(NormalGeneChain));
	int countnum[N+1];
	int Tempotary;

//	int times;
	int i,j;
    int temp;
//    srand((unsigned int)time(NULL));
//    srand((unsigned int)time(NULL));

//	for(times=1;times<GetTimes;times++)
//	{
        memset(countnum,0,sizeof(countnum));
		memset(NormalGeneChain,0,sizeof(NormalGeneChain));
		for(j=1;j<=ProcedureTotal;j++)
		{	//srand((unsigned int)time(NULL));
            temp=rand()%N+1;//printf("%d ",temp);
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
	//	printf("\n");
	DeNormalGene(NormalGeneChain);
//	free(NormalGeneChain);
//	}



}
