#include"jobhead.h"
int counting;
int all;
int *p;
int *value;
int *bestp;
int *recentp;
int mintime;
int evolve(int re)
{
    counting=1;
    int i;
    int ran;
    int avoid[chronum];
    memset(avoid,0,sizeof(avoid));
    if(re==0)
    {
        //for(i=1;i<Nextgen;i++){mcross(i);i++;}

        for(i=1;i<Nextgen;i++)
        {
            ran=rand()%chronum;
            if(ran==0)
            {
                i--;
                continue;
            }
            if(avoid[ran]==0)
            {
                cross(ran);
                avoid[ran]++;
            }
            else i--;
        }
    }
    else addChro();
    memset(avoid,0,sizeof(avoid));
    int lenb=(chronum-1)*Pmutate;
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
            mutate(ran);
            avoid[ran]++;
        }
        else i--;
    }
    memset(avoid,0,sizeof(avoid));
    lenb=(Nextgen-1)*Pmutate;
    for(i=1;i<=lenb;i++)
    {
        ran=rand()%Nextgen;
        if(ran==0)
        {
            i--;
            continue;
        }
        if(avoid[ran]==0)
        {
            mutate2(ran);
            avoid[ran]++;
        }
    }
    freethem();
    return 0;
}
int cross(int flag)
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
    if(generation%2==1)
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
int mcross(int flag)
{
    int ran1,ran2;
    while(1)
    {
        ran1=rand()%chronum;
        if(ran1!=0)break;
    }
    while(1)
    {
        ran2=rand()%chronum;
        if(ran2!=ran1&&ran2!=0)
        {
            mcross2(ran1,ran2,flag);
            break;
        }
    }
    return 0;
}
int mcross2(int a,int b,int flag)
{
    int number[N+1];
    memset(number,0,sizeof(int)*(N+1));
    int ran1,ran2;
    int i;
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
    if(generation%2==1)
    {
        for(i=ran1;i<=ran2;i++)
        {
            number[ChroOne[a][i]]++;
        }
        int x;                           //方便记录chromosome
        int y=1;                         //用来录入至新chromosome
        int cou2=ran1;                   //用来最后的输入
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(ran2+i<=ProcedureTotal){x=ChroOne[b][ran2+i];}
            else if(ran2+i==2*ProcedureTotal){x=ChroOne[b][ProcedureTotal];}
            else {x=ChroOne[b][(ran2+i)%ProcedureTotal];}
            if(number[x]!=0)
            {
                number[x]--;
            }
            else
            {
                if(ran2+y<=ProcedureTotal){ChroSon[flag][ran2+y]=x;}
                else {ChroSon[flag][(ran2+y)%ProcedureTotal]=x;}
                y++;
            }
        }
        while(cou2<=ran2)
        {
            ChroSon[flag][cou2]=ChroOne[a][cou2];
            cou2++;
        }
        decode(ChroSon[flag]);
        if(flag==Nextgen-1)return 0;
        y=1;cou2=ran1;//重置
        int temp1=a;a=b;b=temp1;//交换ab再来一次！
        flag++;
        for(i=ran1;i<=ran2;i++)
        {
            number[ChroOne[a][i]]++;
        }
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(ran2+i<=ProcedureTotal){x=ChroOne[b][ran2+i];}
            else if(ran2+i==2*ProcedureTotal){x=ChroOne[b][ProcedureTotal];}
            else {x=ChroOne[b][(ran2+i)%ProcedureTotal];}
            if(number[x]!=0)
            {
                number[x]--;
            }
            else
            {
                if(ran2+y<=ProcedureTotal){ChroSon[flag][ran2+y]=x;}
                else {ChroSon[flag][(ran2+y)%ProcedureTotal]=x;}
                y++;
            }
        }
        while(cou2<=ran2)
        {
            ChroSon[flag][cou2]=ChroOne[a][cou2];
            cou2++;
        }
        decode(ChroSon[flag]);
    }
    else
    {
        for(i=ran1;i<=ran2;i++)
        {
            number[ChroTwo[a][i]]++;
        }
        int x;                           //方便记录chromosome
        int y=1;                         //用来录入至新chromosome
        int cou2=ran1;                   //用来最后的输入
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(ran2+i<=ProcedureTotal){x=ChroTwo[b][ran2+i];}
            else if(ran2+i==2*ProcedureTotal){x=ChroTwo[b][ProcedureTotal];}
            else {x=ChroTwo[b][(ran2+i)%ProcedureTotal];}
            if(number[x]!=0)
            {
                number[x]--;
            }
            else
            {
                if(ran2+y<=ProcedureTotal){ChroSon[flag][ran2+y]=x;}
                else {ChroSon[flag][(ran2+y)%ProcedureTotal]=x;}
                y++;
            }
        }
        while(cou2<=ran2)
        {
            ChroSon[flag][cou2]=ChroTwo[a][cou2];
            cou2++;
        }
        decode(ChroSon[flag]);
        if(flag==Nextgen-1)return 0;
        y=1;cou2=ran1;//重置
        int temp1=a;a=b;b=temp1;//交换ab再来一次！
        flag++;
        for(i=ran1;i<=ran2;i++)
        {
            number[ChroTwo[a][i]]++;
        }
        for(i=1;i<=ProcedureTotal;i++)
        {
            if(ran2+i<=ProcedureTotal){x=ChroTwo[b][ran2+i];}
            else if(ran2+i==2*ProcedureTotal){x=ChroTwo[b][ProcedureTotal];}
            else {x=ChroTwo[b][(ran2+i)%ProcedureTotal];}
            if(number[x]!=0)
            {
                number[x]--;
            }
            else
            {
                if(ran2+y<=ProcedureTotal){ChroSon[flag][ran2+y]=x;}
                else {ChroSon[flag][(ran2+y)%ProcedureTotal]=x;}
                y++;
            }
        }
        while(cou2<=ran2)
        {
            ChroSon[flag][cou2]=ChroTwo[a][cou2];
            cou2++;
        }
        decode(ChroSon[flag]);
    }
    return 0;
}
int mutate(int flag)
{
    if(N>=4)all=4;
    else all=N;
    p=malloc(sizeof(int)*(all));
    value=malloc(sizeof(int)*(all));
    bestp=malloc(sizeof(int)*(all));
    recentp=malloc(sizeof(int)*(all));
    int i;
    if(generation%2==1)
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
int mutate2(int flag)
{
    int i;
    mintime=decode(ChroSon[flag]);
    for(i=0;i<all;i++)
    {
        while(1)
        {
            p[i]=rand()%ProcedureTotal+1;
            if(!check(p,i))continue;
            value[i]=ChroSon[flag][p[i]];
            if(check(value,i))break;
        }
    }
    for(i=0;i<all;i++)
    {
        bestp[i]=ChroSon[flag][p[i]];
    }
    dfs3(flag,0);
    for(i=0;i<all;i++)
    {
        ChroSon[flag][p[i]]=bestp[i];
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
int dfs3(int flag,int step)
{
    int i;
    if(step==all)
    {
        for(i=0;i<all;i++)
        {
            ChroSon[flag][p[i]]=recentp[i];
        }
        if(decode(ChroSon[flag])<mintime)
        {
            mintime=decode(ChroSon[flag]);
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
            dfs3(flag,step+1);
        }
    }
    return 0;
}
int addChro()
{
    int countnum[N+1];
    int i,j;
    int Arandom;
    int times=0;
	int Atemp;
    int temp;
    for(i=1;i<Nextgen;i++)
    {
        times++;
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
				ChroSon[i][j]=temp;
                countnum[temp]++;
            }
        }
        Arandom=rand()%100+1;
		Atemp=decode(ChroSon[i]);
		if(Atemp>1.05*GreatGeneNum&&Arandom<=GreatGeneNum*1.0*28/Atemp)
	    i--;
    }
    return 0;
}
