#include"jobhead.h"
void Allocate()
{
	int i;
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
