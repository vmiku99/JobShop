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
int main()
{
    srand((unsigned int)time(NULL));
    freopen("test3_3.txt","r",stdin);
    int i;
    scanf("%d%d",&N,&M);
	Allocate();
	input();
    for(i=1;i<=chronum;i++)
	{
		ChroOne[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));
		ChroTwo[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));

	}
//开始
		int times=chronum;
		GreatGeneChain=(int*)malloc(sizeof(int)*(ProcedureTotal+1));
		memset(GreatGeneChain,0,sizeof(int)*(ProcedureTotal+1));
		for(i=1;i<=times;i++)
		GetGreatGene();
		printf("%d\n",GreatGeneNum);
		for(i=1;i<=ProcedureTotal;i++)
		printf("GreatGeneChain:%d\t%d\n",i,GreatGeneChain[i]);
//结束
   Gene_initialize();
   Gene_decode();
   int generation=1;
   while(generation<=30)
   {
       if(generation%2==1)Gene_evolve((int **)ChroOne);
       else Gene_evolve((int **)ChroTwo);
       Roulette(generation);
       generation++;
   }
    return 0;
}


