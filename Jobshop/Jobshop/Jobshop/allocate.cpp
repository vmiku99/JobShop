#include"jobhead.h"
void Allocate()
{
	int i;
	Ma = (int **)malloc(sizeof(int *)*(N + 1));
	Ti = (int **)malloc(sizeof(int *)*(N + 1));
	ChroOne = (int **)malloc(sizeof(int *)*(chronum));
	ChroTwo = (int **)malloc(sizeof(int *)*(chronum));
	ChroSon = (int **)malloc(sizeof(int *)*(Nextgen));
	n_num = (int *)malloc(sizeof(int)*(N + 1));
	memset(n_num, 0, (sizeof(int)*(N + 1)));
	FitFather = (int *)malloc(sizeof(int)*(chronum));
	FitSon = (int *)malloc(sizeof(int)*(Nextgen));
	for (i = 1; i <= N; i++)
	{
		Ma[i] = (int *)malloc(sizeof(int)*(M + 1));
		Ti[i] = (int *)malloc(sizeof(int)*(M + 1));
	}
}
void Allocate2()
{
	int i;
	for (i = 0; i<chronum; i++)
	{
		ChroOne[i] = (int *)malloc(sizeof(int)*(ProcedureTotal + 1));
		ChroTwo[i] = (int *)malloc(sizeof(int)*(ProcedureTotal + 1));
		if (i<Nextgen)ChroSon[i] = (int *)malloc(sizeof(int)*(ProcedureTotal + 1));
	}
	GreatGeneChain = (int*)malloc(sizeof(int)*(ProcedureTotal + 1));
	memset(GreatGeneChain, 0, sizeof(int)*(ProcedureTotal + 1));
	for (i = 1; i<chronum; i++)GetGreatGene();
}
void freepointer()
{
	int i;
	free(n_num);
	free(GreatGeneChain);
	free(FitFather);
	free(FitSon);
	for (i = 1; i <= N; i++)
	{
		free(Ma[i]);
		free(Ti[i]);
	}
	free(Ma);
	free(Ti);
	for (i = 0; i<chronum; i++)
	{
		free(ChroOne[i]);
		free(ChroTwo[i]);
		if (i<Nextgen)free(ChroSon[i]);
	}
	free(ChroOne);
	free(ChroTwo);
	free(ChroSon);
}