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
int average=0;
int generation;
int chronum;
int Nextgen;
int age;
clock_t start;
int main()
{
    start=clock();
    srand((unsigned int)time(NULL));
    freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    chronum=301;age=500;
    Nextgen=(chronum-1)*Pcross+1;
    Allocate();
    input2();
    Allocate2();
    int Pre;
    int repeat=0;int record=0;
    generation=1;
    Gene_initialize();
    while(clock()<290000)
    {
        Pre=GreatGeneNum;
        if(repeat==50){evolve(1);repeat=0;}
        else evolve(0);
        if(generation-record>=250&&(generation-record)%250==0){Gene_initialize();repeat=0;}
        Fitness();
        Roulette();
    //  Championships();
//        printf("generation:%d average:%d\n",generation,average);
        if(GreatGeneNum==Pre)repeat++;
        else {record=generation;repeat=0;}
        generation++;
    }
    OutPut(GreatGeneChain);
    freepointer();
    return 0;
}
