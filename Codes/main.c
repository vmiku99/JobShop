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
int chronum;
int Nextgen;
int age;
clock_t start;
int main()
{
    start=clock();
    srand((unsigned int)time(NULL));
    freopen("la01.txt","r",stdin);
    scanf("%d%d",&N,&M);
    if(N*M>50){chronum=501;age=500;}
    else {chronum=201;age=200;}
    Nextgen=(chronum-1)*Pcross+1;
    Allocate();
    input2();
    Allocate2();
    int Pre;
    int repeat=0;
    Gene_initialize();
    generation=1;
    while(generation<=age)
    {
        if(repeat==20)
        {
            Gene_initialize();
            repeat=0;
        }
        Pre=GreatGeneNum;
        evolve();
        Fitness();
        Roulette();
    //  Championships();
    //  printf("average:%d\n",average[generation]);
        if(GreatGeneNum==Pre)repeat++;
        else repeat=0;
        generation++;
    }
    OutPut(GreatGeneChain);
    freepointer();
    return 0;
}
