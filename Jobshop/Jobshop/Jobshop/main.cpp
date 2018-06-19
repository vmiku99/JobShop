#include"jobhead.h"
int **Ma;
int **Ti;
int N, M;
int *n_num;
int ProcedureTotal = 0;
int **ChroOne;
int **ChroTwo;
int **ChroSon;
int GreatGeneNum = 0;
int *GreatGeneChain;
int *FitFather;
int *FitSon;
int average = 0;
int generation;
int chronum;
int Nextgen;
int age;
clock_t start;
int main()
{
	char Filll[100];
	scanf_s("%s", Filll,100);
	start = clock();
	srand((unsigned int)time(NULL));
	FILE *a;
	freopen_s(&a, Filll, "r", stdin);
	//freopen_s(&a, "abz9.txt", "r", stdin);
	scanf_s("%d%d", &N, &M);
	chronum = 301; age = 500;
	Nextgen = (chronum - 1)*Pcross + 1;
	Allocate();
	input2();
	Allocate2();
	int Pre;
	int repeat = 0;
	generation = 1;
	Gene_initialize();
	while (clock()<30000)
	{
		Pre = GreatGeneNum;
		if (repeat == 50)
		{
			addChro();
			repeat = 0;
		}
		else
		{
			evolve();
		}
		Fitness();
		Roulette();
		//  Championships();
	//	printf("generation:%d average:%d\n", generation, average);
		if (GreatGeneNum == Pre)repeat++;
		else repeat = 0;
		generation++;
	}
	OutPut(GreatGeneChain);
	Paint(GreatGeneChain);
	PPPaint(GreatGeneChain);
	freepointer();
	return 0;
}