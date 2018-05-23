#include"jobhead.h"
int Gene_initialize()/////////////无返回值，带一个参数
{
	int countnum[N+1];
    int i,j;
    int Arandom; 
    int times=0;
	int Atemp;
    int temp;

    for(i=1;i<chronum;i++)
    {	times++;
        memset(countnum,0,sizeof(countnum));
        for(j=1;j<=ProcedureTotal;j++)
        {
            temp=rand()%N+1;

            if(countnum[temp]>=n_num[temp])
            {
                j--;
                continue;
            }
            else
            {
                ChroOne[i][j]=temp;
//                printf("%d ",temp);
                countnum[temp]++;
            }         
        }
        Arandom=rand()%100+1;
        Atemp=decode(ChroOne[i]);
        if(Atemp>1.2*GreatGeneNum&&Arandom>=GreatGeneNum*50/Atemp)
	    i--;
//        printf("%d\n",i);
    }
//    printf("You try %d times to get %d Chain\n",times,chronum);
    return 0;	 
}
