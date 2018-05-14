#include"jobhead.h"
int **Ma;
int **Ti;
int N,M;
int *n_num;
int **Chro;
int ProcedureTotal=0;
void freepointer()
{
    free(Ma);
    free(Ti);
    free(n_num);
    free(Chro);
}
int main()
{
    freopen("test3_3.txt","r",stdin);
    int i,j;
    scanf("%d%d",&N,&M);
    Ma=(int **)malloc(sizeof(int *)*(N+1));
    Ti=(int **)malloc(sizeof(int *)*(N+1));
    Chro=(int **)malloc(sizeof(int *)*(chronum));
    n_num=(int *)malloc(sizeof(int)*(N+1));
    memset(n_num,0,(sizeof(int)*(N+1)));
	for(i=1;i<=N;i++)
    {
        Ma[i]=(int *)malloc(sizeof(int)*(M+1));
        Ti[i]=(int *)malloc(sizeof(int)*(M+1));
    }
    for(i=1;i<=chronum;i++)Chro[i]=(int *)malloc(sizeof(int)*(N*M+1));
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
        //n_num[i]=N;//!!!
	//	printf("%d\t%d\n",i,n_num[i]);
    }


    Gene_initialize();
    Gene_decode();
    freepointer();
    return 0;
}


