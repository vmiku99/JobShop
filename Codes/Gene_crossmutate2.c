#include"jobhead.h"
int counting;
const int all=4;
int *p;
int *value;
int *bestp;
int *recentp;
int mintime;
int evolve(int g)
{
    counting=1;
    int i;
    int ran;
    int avoid[chronum+1];
    memset(avoid,0,sizeof(avoid));
    int lena=(chronum-1)*Pcross;
    int lenb=(chronum-1)*Pmutate;
    for(i=1;i<=lena;i++)
    {
        ran=rand()%chronum;
        if(ran==0)
        {
            i--;
            continue;
        }
        if(avoid[ran]==0)
        {
            cross(ran,g);
            avoid[ran]++;
        }
        else i--;
    }
    memset(avoid,0,sizeof(avoid));
    for(i=1;i<=lenb;i++)
    {
        ran=rand()%chronum;
        if(ran==0)
        {
            i--;
            continue;
        }
        if(avoid[ran]==0)
        {
            mutate(ran,g);
            avoid[ran]++;
        }
        else i--;
    }
    freethem();
    return 0;
}
int cross(int flag,int g)
{
    int po[4];
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        while(1)
        {
            po[i]=rand()%ProcedureTotal+1;
            if(check(po,i))break;
        }
    }
    for(i=3;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(po[j]>po[j+1])
            {
                temp=po[j];
                po[j]=po[j+1];
                po[j+1]=temp;
            }
        }
    }
    int position=1;
    if(g%2==1)
    {
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(i==po[0])
            {
                for(j=po[2];j<=po[3];j++)
                {
                    ChroSon[counting][position]=ChroOne[flag][j];
                    position++;
                }
            }
            else if(i==po[2])
            {
                for(j=po[0];j<=po[1];j++)
                {
                    ChroSon[counting][position]=ChroOne[flag][j];
                    position++;
                }
            }
            else if((i>po[0]&&i<=po[1])||(i>po[2]&&i<=po[3]))continue;
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
            if(i==po[0])
            {
                for(j=po[2];j<=po[3];j++)
                {
                    ChroSon[counting][position]=ChroTwo[flag][j];
                    position++;
                }
            }
            else if(i==po[2])
            {
                for(j=po[0];j<=po[1];j++)
                {
                    ChroSon[counting][position]=ChroTwo[flag][j];
                    position++;
                }
            }
            else if((i>po[0]&&i<=po[1])||(i>po[2]&&i<=po[3]))continue;
            else
            {
                ChroSon[counting][position]=ChroTwo[flag][i];
                position++;
            }
        }

    }
    decode(ChroSon[counting]);
    counting++;
    return 0;
}
int mutate(int flag,int g)
{
    p=malloc(sizeof(int)*(all));
    value=malloc(sizeof(int)*(all));
    bestp=malloc(sizeof(int)*(all));
    recentp=malloc(sizeof(int)*(all));

    int i;
    if(g%2==1)
    {
        mintime=decode(ChroOne[flag]);
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
        for(i=0;i<all;i++)
        {
            bestp[i]=ChroOne[flag][p[i]];
        }
        dfs1(flag,0);
        for(i=0;i<all;i++)
        {
            ChroOne[flag][p[i]]=bestp[i];
        }
    }
    else
    {
        mintime=decode(ChroTwo[flag]);
        for(i=0;i<all;i++)
        {
            while(1)
            {
                p[i]=rand()%ProcedureTotal+1;
                if(!check(p,i))continue;
                value[i]=ChroTwo[flag][p[i]];
                if(check(value,i))break;
            }
        }
        for(i=0;i<all;i++)
        {
            bestp[i]=ChroTwo[flag][p[i]];
        }
        dfs2(flag,0);
        for(i=0;i<all;i++)
        {
            ChroTwo[flag][p[i]]=bestp[i];
        }
    }
    return 0;
}
void freethem()
{
    free(p);
    free(value);
    free(bestp);
    free(recentp);
}
int check(int *a,int recent)
{
    int i;
    for(i=0;i<recent;i++)
    {
        if(a[recent]==a[i])return 0;
    }
    return 1;
}
int dfs1(int flag,int step)
{
    int i;
    if(step==all)
    {
        for(i=0;i<all;i++)
        {
            ChroOne[flag][p[i]]=recentp[i];
        }
        if(decode(ChroOne[flag])<mintime)
        {
            mintime=decode(ChroOne[flag]);
            for(i=0;i<all;i++)
            {
                bestp[i]=recentp[i];
            }
        }
        return 0;
    }
    for(i=0;i<all;i++)
    {
        recentp[step]=value[i];
        if(check(recentp,step))
        {
            dfs1(flag,step+1);
        }
    }
    return 0;
}
int dfs2(int flag,int step)
{
    int i;
    if(step==all)
    {
        for(i=0;i<all;i++)
        {
            ChroTwo[flag][p[i]]=recentp[i];
        }
        if(decode(ChroTwo[flag])<mintime)
        {
            mintime=decode(ChroTwo[flag]);
            for(i=0;i<all;i++)
            {
                bestp[i]=recentp[i];
            }
        }
        return 0;
    }
    for(i=0;i<all;i++)
    {
        recentp[step]=value[i];
        if(check(recentp,step))
        {
            dfs2(flag,step+1);
        }
    }
    return 0;
}
