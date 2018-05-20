#include"jobhead.h"
int counting=1;
int evolve(int g)
{
    int i;
    int ran;
    int avoid[(int)(chronum*Pcross)];
    memset(avoid,0,sizeof(avoid));
    for(i=1;i<=chronum*Pcross;i++)
    {
        ran=rand()%chronum+1;
        if(avoid[ran]==0)
        {
            cross(ran,g);
            avoid[ran]++;
        }
        else i--;
    }
    memset(avoid,0,sizeof(avoid));
    for(i=1;i<=chronum*Pmutate;i++)
    {
        ran=rand()%chronum+1;
        if(avoid[ran]==0)
        {
            mutate(ran,g);
            avoid[ran]++;
        }
        else i--;
    }
    return 0;
}
int cross(int flag,int g)
{
    int p[4];
    p[0]=rand()%ProcedureTotal+1;
    while(1)
    {
        p[1]=rand()%ProcedureTotal+1;
        if(p[1]!=p[0])break;
    }
    while(1)
    {
        p[2]=rand()%ProcedureTotal+1;
        if(p[2]!=p[1]&&p[2]!=p[0])break;
    }
    while(1)
    {
        p[3]=rand()%ProcedureTotal+1;
        if(p[3]!=p[0]&&p[3]!=p[1]&&p[3]!=p[2])break;
    }
    int i,j,temp;
    for(i=3;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int position=1;
    if(g%2==1)
    {
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(i==p[0])
            {
                for(j=p[2];j<=p[3];j++)
                {
                    ChroSon[counting][position]=ChroOne[flag][j];
                    position++;
                }
                i+=p[3]-p[2];
            }
            else if(i==p[2])
            {
                for(j=p[0];j<=p[1];j++)
                {
                    ChroSon[counting][position]=ChroOne[flag][j];
                    position++;
                }
                i+=p[1]-p[0];
            }
            else
            {
                ChroSon[counting][position]=ChroOne[flag][i];
                position++;
            }
        }
    }
    else
    {
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(i==p[0])
            {
                for(j=p[2];j<=p[3];j++)
                {
                    ChroSon[counting][position]=ChroTwo[flag][j];
                    position++;
                }
                i+=p[3]-p[2];
            }
            else if(i==p[2])
            {
                for(j=p[0];j<=p[1];j++)
                {
                    ChroSon[counting][position]=ChroTwo[flag][j];
                    position++;
                }
                i+=p[1]-p[0];
            }
            else
            {
                ChroSon[counting][position]=ChroTwo[flag][i];
                position++;
            }
        }
    }
    counting++;
    return 0;
}
int mutate(int flag,int g)
{
    const int all=4;
    int p[all];
    int value[all];
    int i,j,k;
    int bestp[all];
    int recentp[all];
    int mintime;
    int res=factor(all);
    if(g%2==1)
    {
        for(i=0;i<all;i++)
        {
            while(1)
            {
                p[i]=rand()%ProcedureTotal+1;
                if(!check(p,i))continue;
                value[i]=ChroOne[flag][p[i]];
                if(check(value,i))break;
            }
        }
    }

    return 0;
}
int check(int a[],int recent)
{
    int i;
    for(i=0;i<recent;i++)
    {
        if(a[recent]==a[i])return 0;
    }
    return 1;
}
int factor(int i)
{
    int res=1;
    while(i>0)
    {
        res*=i;
        i--;
    }
    return res;
}
