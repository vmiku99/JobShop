#include"jobhead.h"
void Gene_decode()
{
//    int TimeTotal[chronum]; //各组总时间
    int maxTime=0;   //当前组总时间
    int TimeMachine[M+1];//机器最后时间
    int TimeTool[N+1];//工件最后时间
    int TimesTool[N+1];//工件次数
    int i,j,k;
    int timeStart;
    int temp;
    memset(TimeMachine,0,sizeof(TimeMachine));
    memset(TimeTool,0,sizeof(TimeTool));
    memset(TimesTool,0,sizeof(TimesTool));

	for(i=1;i<=chronum-1;i++)
    {
        for(j=1;j<=ProcedureTotal;j++)
        {
            temp=Chro[i][j];
           // for(k=TimesTool[temp];!(Ti[temp][k]);k++)
           // ;
        	k=++TimesTool[temp];

//			if(k>n_num[temp])
//        	k=n_num[temp];

//
//            timeStart=(TimeTool[temp]>TimeMachine[Ma[temp][k]])?TimeTool[temp]:TimeMachine[Ma[temp][k]];
//            TimeTool[temp]=TimeMachine[Ma[temp][k]]=timeStart+Ti[temp][k];
//            maxTime=(maxTime>TimeTool[temp])?maxTime:TimeTool[temp];
//
//		printf("temp:%d\tTimesTool:%d\tMa:%d\tTime:%d\n",temp,TimesTool[temp],Ma[temp][k],Ti[temp][k]);
		 	timeStart=Max(TimeTool[temp],TimeMachine[Ma[temp][k]]);
            TimeTool[temp]=TimeMachine[Ma[temp][k]]=timeStart+Ti[temp][k];
            maxTime=Max(maxTime,TimeTool[temp]);

		 }
//        TimeTotal[i]=maxTime;
		Chro[i][0]=maxTime;
//		maxTime=0;
//		printf("%d\t%d\n",TimeTotal[i],maxTime);
//		printf("%d\n",maxTime);
		memset(TimesTool,0,sizeof(TimesTool));
		memset(TimeTool,0,sizeof(TimeTool));
    	memset(TimeMachine,0,sizeof(TimeMachine));
		maxTime = 0 ;
	}

	int *ptr=(int *)malloc(sizeof(int)*chronum);
	int *pptr=(int *)malloc(sizeof(int)*chronum);
	int a,b;
	memset(ptr,0,sizeof(int)*chronum);
	memset(pptr,0,sizeof(int)*chronum);
	for(a=1;a<=chronum-1;a++)
	{//	printf("TIMETOTAL%d\n",TimeTotal[a]);
		for(b=1;ptr[b]!=0&&Chro[a][0]!=ptr[b]&&b<=chronum-1;b++);
		if(Chro[a][0]==ptr[b])
	{
		pptr[b]++;
	//	printf("GG      %dTIMETOTAL%d\n",TimeTotal[a],b);
	}
		else {

		ptr[b]=Chro[a][0];
		pptr[b]++;
		}
	}
	for(a=1;ptr[a]!=0&&pptr[a]!=0;a++)
	printf("Time:%d\tTimes:%d\t%d\n",ptr[a],pptr[a],a);

	free(pptr);
	free(ptr);


}
