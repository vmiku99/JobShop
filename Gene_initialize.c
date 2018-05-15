#include"jobhead.h"
int Gene_initialize()/////////////无返回值，带一个参数
{
	int countnum[N+1];
    int i,j;
    int Arandom; 
    int nnnnnn=0;
	int Atemp;
    int temp;
//    srand((unsigned int)time(NULL));
    for(i=1;i<=chronum-1;i++)
    {	nnnnnn++;
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
                ChroOne[i][j]=temp;
//                printf("%d ",temp);
                countnum[temp]++;
            }         
        }
        Arandom=rand()%100+1;
        Atemp=DeNormalGene(ChroOne[i]);
        if(Atemp>1.2*GreatGeneNum&&Arandom>=GreatGeneNum*50/Atemp)
	    i--;
//        printf("%d\n",i);
    }
    printf("The number of Chro is %d\n",nnnnnn);
    return 0;	 
}
