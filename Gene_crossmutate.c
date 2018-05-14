#include"jobhead.h"
int Gene_evolve(int *Chromosome)
{
    const int canshu=2;
    int i;
    int ran;
    for(i=chronum/canshu+1;i<chronum;i++)
    {
        ran=rand()%100+1;
        if(ran<=5)
        {
            Gene_mutate(&Chromosome,i);
        }
        else
        {
            Gene_cross1(&Chromosome,i);
            i++;
        }
    }
}
int Gene_mutate(int *Chromosome,int flag)
{
    int ran;
    while(1)
    {
        ran=rand()%chronum;
        if(ran==0||ran==1)continue;
        else break;
    }
    int i;
    int ran1,ran2;
    ran1=rand()%ProcedureTotal+1;
    while(1)
    {
        ran2=rand()%ProcedureTotal+1;
        if(ran2!=ran1)
        {
            int j;
            for(j=1;j<=ProcedureTotal;j++)
            {
                if(j!=ran1&&j!=ran2)
                {
                    Chromosome[flag][j]=Chromosome[ran][j];
                }
                else if(j==ran1)
                {
                    Chromosome[flag][j]=Chromosome[ran][ran2];
                }
                else if(j==ran2)
                {
                    Chromosome[flag][j]=Chromosome[ran][ran1];
                }
            }
            break;
        }
    }
    return 0;
}
int Gene_cross1(int *Chromosome,int flag)
{
    int ran1,ran2;
    while(1)
    {
        ran1=rand()%ProcedureTotal+1;
        if(ran1!=1)break;
    }
    while(1)
    {
        ran2=rand()%ProcedureTotal+1;
        if(ran2!=ran1&&ran2!=1)
        {
            Gene_cross2(ran1,ran2,&Chromosome,flag);
            break;
        }
    }
    return 0;
}
int Gene_cross2(int a,int b,int *Chromosome,int flag)
{
    int ran1,ran2;
    int i;
    int cross[ProcedureTotal+1];
    ran1=rand()%ProcedureTotal+1;
    while(1)
    {
        ran2=rand()%ProcedureTotal+1;
        if(ran2!=ran1)break;
    }
    if(ran1>ran2)
    {
        int temp;
        temp=ran1;
        ran1=ran2;
        ran2=temp;
    }
    int x;                           //方便记录chromosome
    int y=1;                         //用来录入至新chromosome
    int cou=ran1;                    //用来检验是否与另一条染色体对应片段相等
    int cou2=ran1;                   //用来最后的输入
    for(i=1;i<=ProcedureTotal;i++)
    {
        if(y==ProcedureTotal-(ran2-ran1))
        {
            for(y=y;y<=ProcedureTotal;y++)
            {
                Chromosome[flag][y]=Chromosome[a][cou2];
                cou2++;
            }
        }
        if(ran2+i<ProcedureTotal)
        {
            x=Chromosome[b][(ran2+i)%ProcedureTotal];
        }
        else x=Chromosome[b][(ran2+i)%ProcedureTotal+1];
        if(x!=Chromosome[a][cou])
        {
            if(ran2+y<ProcedureTotal)Chromosome[flag][(ran2+y)%ProcedureTotal]=x;
            else Chromosome[flag][(ran2+y)%ProcedureTotal+1]=x;
            y++;
        }
        else
        {
            cou++;
        }
    }
    if(flag==chronum-1)return 0;
    y=1;cou=ran1;cou2=ran1;//重置
    int temp=a;a=b;b=temp;//交换ab再来一次！
    flag++;
    for(i=1;i<=ProcedureTotal;i++)
    {
        if(y==ProcedureTotal-(ran2-ran1))
        {
            for(y=y;y<=ProcedureTotal;y++)
            {
                Chromosome[flag][y]=Chromosome[a][cou2];
                cou2++;
            }
        }
        if(ran2+i<ProcedureTotal)
        {
            x=Chromosome[b][(ran2+i)%ProcedureTotal];
        }
        else x=Chromosome[b][(ran2+i)%ProcedureTotal+1];
        if(x!=Chromosome[a][cou])
        {
            if(ran2+y<ProcedureTotal)Chromosome[flag][(ran2+y)%ProcedureTotal]=x;
            else Chromosome[flag][(ran2+y)%ProcedureTotal+1]=x;
            y++;
        }
        else
        {
            cou++;
        }
    }
    return 0;
}
