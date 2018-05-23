#include"jobhead.h"
void Allocate()
{
	int i;
	average=(int*)malloc(sizeof(int)*(age+1));
	memset(average,0,sizeof(int)*(age+1));
	Ma=(int **)malloc(sizeof(int *)*(N+1));
    Ti=(int **)malloc(sizeof(int *)*(N+1));
    ChroOne=(int **)malloc(sizeof(int *)*(chronum));
    ChroTwo=(int **)malloc(sizeof(int *)*(chronum));
    ChroSon=(int **)malloc(sizeof(int *)*(chronum));
    n_num=(int *)malloc(sizeof(int)*(N+1));
    memset(n_num,0,(sizeof(int)*(N+1)));
    FitFather=(int *)malloc(sizeof(int)*(chronum));
    FitSon=(int *)malloc(sizeof(int)*(chronum));
	for(i=1;i<=N;i++)
    {
        Ma[i]=(int *)malloc(sizeof(int)*(M+1));
        Ti[i]=(int *)malloc(sizeof(int)*(M+1));
    }
}
void freepointer()
{
    int i;
    free(average);
    free(n_num);
    free(GreatGeneChain);
    free(FitFather);
    free(FitSon);
    for(i=1;i<=N;i++)
    {
        free(Ma[i]);
        free(Ti[i]);
    }
    free(Ma);
    free(Ti);
    for(i=0;i<chronum;i++)
	{
		free(ChroOne[i]);
		free(ChroTwo[i]);
        free(ChroSon[i]);
	}
	free(ChroOne);
	free(ChroTwo);
	free(ChroSon);
}
