#include"jobhead.h"
int Gene_initialize()
{
	int countnum[N+1];
    int i,j;
    int temp;
    int ProcedureTotal=0;
    for(i=1;i<=N;i++)
    ProcedureTotal+=n_num[i];
    srand((unsigned int)time(NULL));
    for(i=1;i<=chronum-1;i++)
    {
        memset(countnum,0,sizeof(countnum));
        for(j=1;j<=ProcedureTotal;j++)
        {
            temp=rand()%N+1;
            if(countnum[temp]>=n_num[temp])
            {
           	 //if(ProcedureTotal==j)
                j--;
                continue;
            }
            else
            {
                Chro[i][j]=temp;
                printf("%d ",temp);
                countnum[temp]++;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}
