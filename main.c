#include"jobhead.h"
int **Ma;
int **Ti;
int N,M;
int *n_num;
int **ChroOne;
int ProcedureTotal=0;

//开始 
	int GreatGeneNum=0;
	int *GreatGeneChain	;
	int *FitFather;
	int *FitSon;
	int **ChroTwo;
	int **ChroSon;

//结束 
void freepointer()
{
    free(Ma);
    free(Ti);
    free(n_num);
    free(ChroOne);
}
int main()
{	srand((unsigned int)time(NULL));
    freopen("test2_2.txt","r",stdin);
    int i,j;
    scanf("%d%d",&N,&M);
	Allocate();
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            scanf("%d%d",&Ti[i][j],&Ma[i][j]);
            if(Ti[i][j]!=0)
			{
			    n_num[i]++;
			    ProcedureTotal++;
			}
        }
	}
    for(i=1;i<=chronum;i++)
	{
		ChroOne[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));
		ChroTwo[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));

	}	
//开始
		int times=chronum;
		GreatGeneChain=(int*)malloc(sizeof(int)*(ProcedureTotal+1)); 
		memset(GreatGeneChain,0,sizeof(GreatGeneChain));
		for(i=1;i<=times;i++)
		GetGreatGene();
		printf("%d\n",GreatGeneNum);
		for(i=1;i<=ProcedureTotal;i++)
		printf("GreatGeneChain:%d\t%d\n",i,GreatGeneChain[i]);
//结束 



   Gene_initialize();
   Gene_decode();
 //  freepointer();
    return 0;
}


