#include"jobhead.h"
struct Result{
	int start;
	int stop;
	int times;
	int tool;
	struct Result* next;

};
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
void OutPut(int* NormalGeneChain)
{
    int *TimeTool=(int*)malloc(sizeof(int)*(N+1));
    int *TimesTool=(int*)malloc(sizeof(int)*(N+1));
	int *TimeMachine=(int*)malloc(sizeof(int)*(M+1));
	int timeStart=-1;
    int temp;
    int maxTime=0;
    int i,j,k;
    int c,d;
    memset(TimeMachine,0,sizeof(int)*(M+1));
    memset(TimeTool,0,sizeof(int)*(N+1));
    memset(TimesTool,0,sizeof(int)*(N+1));
	int **MaTimeStart=(int**)malloc(sizeof(int*)*(M+1));
	int **MaTimeStop=(int**)malloc(sizeof(int*)*(M+1));

	for(i=0;i<=M;i++)
	{
	MaTimeStart[i]=(int*)malloc(sizeof(int)*(N+1));
	MaTimeStop[i]=(int*)malloc(sizeof(int)*(N+1));		
    memset(MaTimeStart[i],0,sizeof(int)*(N+1));
    memset(MaTimeStop[i],0,sizeof(int)*(N+1));
	}
	
	struct Result** result=(struct Result**)malloc(sizeof(struct Result*)*(M+1));
	//memset(result,0,sizeof(struct Result*)*(M+1));
	struct Result* TT =NULL;
	struct Result* PP =NULL;
    for(i=0;i<=M;i++)
    	{result[i]=(struct Result*)malloc(sizeof(struct Result));
    	result[i]->next=NULL;
    	}
    int ma,a;
	for(j=1;j<=ProcedureTotal;j++)
	{	temp=NormalGeneChain[j];
//		printf("deTemp:%d \n",temp);
   		k=++TimesTool[temp];
		ma=Ma[temp][k];
		TT=result[ma];
	//	printf("temp:%2d k:%2d ma:%2d Ti:%2d\n",temp,k,ma,Ti[temp][k]);
	   	for(a=1;MaTimeStop[ma][a]!=0&&timeStart==-1;a++)
	   		{if(MaTimeStart[ma][a+1]-MaTimeStop[ma][a]>=Ti[temp][k]&&(MaTimeStop[ma][a]>=TimeTool[temp]||MaTimeStart[ma][a+1]-Ti[temp][k]>=TimeTool[temp]))
	   			timeStart=MaTimeStop[ma][a];
	   		}	
		a--;
		TT=result[ma];
	   	if(timeStart==-1) 
 		{	for(a=1;MaTimeStop[ma][a]!=0;a++)
		 	;
			timeStart=Max(TimeTool[temp],TimeMachine[ma]);
			MaTimeStart[ma][a]=timeStart;
 			TimeMachine[ma]=TimeTool[temp]=MaTimeStop[ma][a]=timeStart+Ti[temp][k]; 	
 			while(TT->next!=NULL)
				TT=TT->next;
 			TT->next=(struct Result*)malloc(sizeof(struct Result));
 			TT->start=timeStart;
 			TT->stop=TimeMachine[ma];
 			TT->times=k;
 			TT->tool=temp;
		 	TT->next->next=NULL;
 		}
 		else if(MaTimeStop[ma][a]>=TimeTool[temp]) 
 		{	//printf("qc\n");
 			while(TT->stop!=timeStart)
				TT=TT->next;
			PP=TT->next;
 			TT->next=(struct Result*)malloc(sizeof(struct Result));
 			TT=TT->next;
  			TT->times=k;
 			TT->tool=temp;
  			TT->start=timeStart;	
			MaTimeStop[ma][a]+=Ti[temp][k];
 			TT->stop=TimeTool[temp]=MaTimeStop[ma][a];
 			TT->next=PP;
 		}
 		else 
 		{	while(TT->stop!=MaTimeStop[ma][a])
 				TT=TT->next;
 			PP=TT->next;
 			TT->next=(struct Result*)malloc(sizeof(struct Result));
 			TT=TT->next;
  			TT->times=k;
 			TT->tool=temp;
 			TT->stop=TimeTool[temp]=MaTimeStart[ma][a+1];
 			MaTimeStart[ma][a+1]-=Ti[temp][k];
		 	TT->start=MaTimeStart[ma][a+1];
		 	TT->next=PP;
		 }
    	timeStart=-1;
	}
	free(TimeMachine);
	free(TimesTool);
	free(TimeTool);
	
	for(i=1;i<=M;i++)
	{
		printf("M%-2d ",i);
		for(TT=result[i];TT->next!=NULL;TT=TT->next)
		printf("(%-3d,%-2d-%2d,%3d) ",TT->start,TT->tool,TT->times,TT->stop);
		printf("\n");	
	}	
	printf("End %d",NormalGeneChain[0]);
	for(i=0;i<=M;i++)
	{
	free(MaTimeStart[i]);
    free(MaTimeStop[i]);
	}
	free(MaTimeStart);
	free(MaTimeStop);
	for(i=0;i<=M;i++)
	Freestruct(result[i]);
	free(result);
}
void Freestruct(struct Result* rr)
{
	if(rr->next!=NULL)
	Freestruct(rr->next);
	else free(rr);
}
