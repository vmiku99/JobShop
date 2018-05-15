#include"jobhead.h"
int input()
{
    char a[501];
    int i,j;
    int y;
    int flag;
    int num;
    while(1)
    {
        gets(a);
        if(a[0]>='0'&&a[0]<='9')break;
    }
    for(i=1;i<=N;i++)
    {
        num=0;
        flag=1;
        if(i!=1)gets(a);
        y=strlen(a);
        for(j=0;j<y;j++)
        {
            if(a[j]=='(')
            {
                num=0;
            }
            else if(a[j]==',')
            {
                Ti[i][flag]=num;
                num=0;
            }
            else if(a[j]==')')
            {
                Ma[i][flag]=num;
                flag++;
                n_num[i]++;
                ProcedureTotal++;
                num=0;
            }
            else if(a[j]>='0'&&a[j]<='9')
            {
                num=num*10+a[j]-'0';
            }
            else continue;
        }
    }
    return 0;
}
