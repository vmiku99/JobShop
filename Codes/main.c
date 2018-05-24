#include"jobhead.h"
int **Ma;
int **Ti;
int N,M;
int *n_num;
int ProcedureTotal=0;
int **ChroOne;
int **ChroTwo;
int **ChroSon;
int GreatGeneNum=0;
int *GreatGeneChain;
int *FitFather;
int *FitSon;
int *average;
int generation;
int main()
{
    srand((unsigned int)time(NULL));
    freopen("test6_6.txt","r",stdin);
    int i,j;
    scanf("%d%d",&N,&M);
	Allocate();
	input();
   /* for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            scanf("%d%d",&Ma[i][j],&Ti[i][j]);
            Ma[i][j]++;
            n_num[i]++;
            ProcedureTotal++;
        }
    }*/
    for(i=0;i<chronum;i++)
	{
		ChroOne[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));
		ChroTwo[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));
        if(i<Nextgen)ChroSon[i]=(int *)malloc(sizeof(int)*(ProcedureTotal+1));
	}
		GreatGeneChain=(int*)malloc(sizeof(int)*(ProcedureTotal+1));
		memset(GreatGeneChain,0,sizeof(int)*(ProcedureTotal+1));
		generation=1;
		for(i=1;i<chronum;i++)
		GetGreatGene();
//		for(i=1;i<=ProcedureTotal;i++)
//		printf("GreatGeneChain:%d\t%d\n",i,GreatGeneChain[i]);

   Gene_initialize();
   while(generation<=age)
   {
        evolve(generation);
      	//Fitness();
        //Roulette();
        Championships();
        //Gene_decode();
 //   	printf("average:%d\n",average[generation]);
	   	generation++;
   }
   for(i=1;i<=ProcedureTotal;i++)
   {
       printf("%d ",GreatGeneChain[i]);
   }
   printf("\n");
//	printf("Bang!\nBang!!\nBang!!!\nYou got the Great Number:%d\nLet's Play OW!!!\n'",GreatGeneNum);
//	for(i=1;i<=ProcedureTotal;i++)
//	printf("GreatGeneChain:%d\t%d\n",i,GreatGeneChain[i]);
	Table(GreatGeneChain);
	freepointer();
    return 0;
}


