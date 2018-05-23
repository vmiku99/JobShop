#include"jobhead.h"
int Gene_evolveodd()
{
    int i;
    int ran;
    for(i=1;i<chronum;i++)
    {
        ran=rand()%100+1;
        if(ran<=20)
        {
            Gene_mutateodd(i);
        }
        else
        {
            Gene_cross1odd(i);
            i++;
        }
    }
    return 0;
}
int Gene_mutateodd(int flag)
{
    int ran;
    while(1)
    {
        ran=rand()%chronum;
        if(ran!=0)break;
    }
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
                    ChroSon[flag][j]=ChroOne[ran][j];
                }
                else if(j==ran1)
                {
                    ChroSon[flag][j]=ChroOne[ran][ran2];
                }
                else if(j==ran2)
                {
                    ChroSon[flag][j]=ChroOne[ran][ran1];
                }
            }
            break;
        }
    }
    decode(ChroSon[flag]);
    return 0;
}
int Gene_cross1odd(int flag)
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
            Gene_cross2odd(ran1,ran2,flag);
            break;
        }
    }
    return 0;
}
int Gene_cross2odd(int a,int b,int flag)
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
    if(flag==chronum-1)return 0;
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
    return 0;
}
////////////////////////////////////////////////////////////////////////
int Gene_evolveeven()
{
    int i;
    int ran;
    for(i=1;i<chronum;i++)
    {
        ran=rand()%100+1;
        if(ran<=20)
        {
            Gene_mutateeven(i);
        }
        else
        {
            Gene_cross1even(i);
            i++;
        }
    }
    return 0;
}

int Gene_mutateeven(int flag)
{
    int ran;
    while(1)
    {
        ran=rand()%chronum;
        if(ran==0||ran==1)continue;
        else break;
    }
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
                    ChroSon[flag][j]=ChroTwo[ran][j];
                }
                else if(j==ran1)
                {
                    ChroSon[flag][j]=ChroTwo[ran][ran2];
                }
                else if(j==ran2)
                {
                    ChroSon[flag][j]=ChroTwo[ran][ran1];
                }
            }
            break;
        }
    }
    decode(ChroSon[flag]);
    return 0;
}

int Gene_cross1even(int flag)
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
            Gene_cross2even(ran1,ran2,flag);
            break;
        }
    }
    return 0;
}

int Gene_cross2even(int a,int b,int flag)
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
    if(flag==chronum-1)return 0;
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
    return 0;
}
