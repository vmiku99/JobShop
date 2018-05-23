#include"jobhead.h"
void Table(int* NormalGeneChain)
{
    int *TimeTool=(int*)malloc(sizeof(int)*(N+1));
    int *TimesTool=(int*)malloc(sizeof(int)*(N+1));
	int *TimeMachine=(int*)malloc(sizeof(int)*(M+1));
	int timeStart;
    int temp;
    int maxTime=0;
    int i,j,k;
    memset(TimeMachine,0,sizeof(int)*(M+1));
    memset(TimeTool,0,sizeof(int)*(N+1));
    memset(TimesTool,0,sizeof(int)*(N+1));
//    int *MaStart=(int*)malloc(sizeof(int)*(M+1));
//    int *MaStop=(int*)malloc(sizeof(int)*(M+1));
//    memset(MaStart,0,sizeof(int)*(M+1));
//    memset(MaStop,0,sizeof(int)*(M+1));
//    int MaTimeStart[M+1]][N+1]={0};
//    int MaTimeStop[M+1][N+1]={0};
//    int MaTiTool[M+1][N+1]={0};
    int MaTimeStart[M+1][N+1];
    int MaTimeStop[M+1][N+1];
    int MaTiTool[M+1][N+1];
	for(i=0;i<M;i++)
	{	
    memset(MaTimeStart[i],0,sizeof(int)*(N+1));
    memset(MaTimeStop[i],0,sizeof(int)*(N+1));
    memset(MaTiTool[i],0,sizeof(int)*(N+1));
}
    int ma;
    int MaTimes[N+1];
    memset(MaTimes,0,sizeof(int)*(N+1));
    int papa;
	for(j=1;j<=ProcedureTotal;j++)
	{
	    temp=NormalGeneChain[j];
   		k=++TimesTool[temp];
	   	ma=Ma[temp][k];
 		timeStart= Max(TimeTool[temp],TimeMachine[ma]);
		papa=++MaTimes[ma];
		TimeTool[temp]=TimeMachine[ma]=timeStart+Ti[temp][k];
    	MaTimeStart[ma][papa]=timeStart+1;
    	MaTimeStop[ma][papa]=TimeTool[temp];
        maxTime=Max(maxTime,TimeTool[temp]);
    	MaTiTool[ma][papa]=temp;
		}
	int start=time(NULL);
	int Time=0;
	int end;
	int specific=0;
	int t;
	int kkkk=0;
/*	while(specific<NormalGeneChain[0])
	{
//		while(Time<specific)
//		{end=time(NULL);
//		Time=end-start;}//time

		specific++;//µ±Ç°µÄÃë
//		for(i=1;i<=M+1;i++)
//			printf("\r");
		printf("Ma ");
		for(t=1;t<=specific+10;t+=10)
			printf("%-10d",t);
		printf("\n");
		for(i=1;i<=M;i++)
		{	t=1;
			printf("%-3d",i);
			for(j=1;j<=specific;j++)
			{
				while(j>MaTimeStop[i][t]&&MaTimeStop[i][t]!=0)
					t++;
				if(MaTimeStart[i][t]<=j&&j<=MaTimeStop[i][t])
					printf("%d",MaTiTool[i][t]);
				//	printf("*");
				else printf(" ");
			}
			printf("#%d\n",specific);
		}
	}
*/

		specific=NormalGeneChain[0];
		printf("Ma ");
		for(t=1;t<=specific+10;t+=10)
			printf("%-10d",t);
		printf("\n");
		for(i=1;i<=M;i++)
		{	t=1;
			printf("%-3d",i);
			for(j=1;j<=specific;j++)
			{
				while(j>MaTimeStop[i][t]&&MaTimeStop[i][t]!=0)
					t++;
				if(MaTimeStart[i][t]<=j&&j<=MaTimeStop[i][t])
					printf("%d",MaTiTool[i][t]);
				//	printf("*");
				else printf(" ");
			}
			printf("#%d\n",specific);
		}
	free(TimeMachine);
	free(TimesTool);
	free(TimeTool);
	return ;
}

