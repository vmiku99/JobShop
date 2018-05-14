#include"jobhead.h"
int Gene_initialize()/////////////无返回值，带一个参数
{
	int countnum[N+1];
    int i,j;
    int temp;
//    srand((unsigned int)time(NULL));
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
