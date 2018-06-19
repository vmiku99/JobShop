#include"jobhead.h"
void Paint(int* NormalGeneChain)
{
	int *TimeTool = (int*)malloc(sizeof(int)*(N + 1));
	int *TimesTool = (int*)malloc(sizeof(int)*(N + 1));
	int *TimeMachine = (int*)malloc(sizeof(int)*(M + 1));
	int timeStart = -1;
	int temp;
	int i, j, k;
	memset(TimeMachine, 0, sizeof(int)*(M + 1));
	memset(TimeTool, 0, sizeof(int)*(N + 1));
	memset(TimesTool, 0, sizeof(int)*(N + 1));
	int **MaTimeStart = (int**)malloc(sizeof(int*)*(M + 1));
	int **MaTimeStop = (int**)malloc(sizeof(int*)*(M + 1));

	for (i = 0; i <= M; i++)
	{
		MaTimeStart[i] = (int*)malloc(sizeof(int)*(N + 1));
		MaTimeStop[i] = (int*)malloc(sizeof(int)*(N + 1));
		memset(MaTimeStart[i], 0, sizeof(int)*(N + 1));
		memset(MaTimeStop[i], 0, sizeof(int)*(N + 1));
	}

	struct Result** result = (struct Result**)malloc(sizeof(struct Result*)*(M + 1));
	//memset(result,0,sizeof(struct Result*)*(M+1));
	struct Result* TT = NULL;
	struct Result* PP = NULL;
	for (i = 0; i <= M; i++)
	{
		result[i] = (struct Result*)malloc(sizeof(struct Result));
		result[i]->next = NULL;
	}
	int ma, a;
	for (j = 1; j <= ProcedureTotal; j++)
	{
		temp = NormalGeneChain[j];
		k = ++TimesTool[temp];
		ma = Ma[temp][k];
		TT = result[ma];
		for (a = 1; MaTimeStop[ma][a] != 0 && timeStart == -1; a++)
		{
			if (MaTimeStart[ma][a + 1] - MaTimeStop[ma][a] >= Ti[temp][k] && (MaTimeStop[ma][a] >= TimeTool[temp] || MaTimeStart[ma][a + 1] - Ti[temp][k] >= TimeTool[temp]))
				timeStart = MaTimeStop[ma][a];
		}
		a--;
		TT = result[ma];
		if (timeStart == -1)
		{
			for (a = 1; MaTimeStop[ma][a] != 0; a++)
				;
			timeStart = Max(TimeTool[temp], TimeMachine[ma]);
			MaTimeStart[ma][a] = timeStart;
			TimeMachine[ma] = TimeTool[temp] = MaTimeStop[ma][a] = timeStart + Ti[temp][k];
			while (TT->next != NULL)
				TT = TT->next;
			TT->next = (struct Result*)malloc(sizeof(struct Result));
			TT->start = timeStart;
			TT->stop = TimeMachine[ma];
			TT->times = k;
			TT->tool = temp;
			TT->kind = 1;
			TT->next->next = NULL;
		}
		else if (MaTimeStop[ma][a] >= TimeTool[temp])
		{
			while (TT->stop != timeStart)
				TT = TT->next;
			PP = TT->next;
			TT->next = (struct Result*)malloc(sizeof(struct Result));
			TT = TT->next;
			TT->times = k;
			TT->tool = temp;
			TT->start = timeStart;
			MaTimeStop[ma][a] += Ti[temp][k];
			TT->stop = TimeTool[temp] = MaTimeStop[ma][a];
			TT->kind = 2;
			TT->next = PP;
		}
		else
		{
			while (TT->stop != MaTimeStop[ma][a])
				TT = TT->next;
			PP = TT->next;
			TT->next = (struct Result*)malloc(sizeof(struct Result));
			TT = TT->next;
			TT->times = k;
			TT->tool = temp;
			TT->stop = TimeTool[temp] = MaTimeStart[ma][a + 1];
			MaTimeStart[ma][a + 1] -= Ti[temp][k];
			TT->start = MaTimeStart[ma][a + 1];
			TT->kind = 3;
			TT->next = PP;
		}
		timeStart = -1;
	}


	int size = NormalGeneChain[0];
	int**tt;
	tt = (int**)malloc(sizeof(int*)*(M + 1));
	for (i = 0; i <= M; i++)
	{
		tt[i] = (int*)malloc(sizeof(int)*(2 * size + 1));
		memset(tt[i], 0, sizeof(int)*(2 * size + 1));
		tt[i][0] = -1;
	}
	for (i = 1; i <= M; i++)
	{
		for (TT = result[i]; TT->next != NULL; TT = TT->next)
		{
			for (j = TT->start + 1; j <= TT->stop; j++)
				tt[i][j] = TT->tool;
		}
	}


	initgraph(1.3 * size, M * 50 + 80, SHOWCONSOLE);
	char g = 'M';
	TCHAR b[6];
	TCHAR T[6];
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);


	for (i = 1; i <= M; i++)
	{
		outtextxy(0.1*size, i * 50, g);
		_stprintf_s(b, _T("%d"), i - 1);
		outtextxy(0.1*size + 15, i * 50, b);
		line(0.1*size + 40, i * 50 + 10, 1.1*size + 40, i * 50 + 10);
	}

	settextstyle(10, 0, _T("宋体"));

	TCHAR ss[100];
	char bb[100];
	int TTime = 1;
	int Size = size;
	int* TimesToolCount = (int*)malloc(sizeof(int)*(N + 1));
	memset(TimesToolCount, 0, sizeof(int)*(N + 1));
	for (TTime = 1; TTime <= Size; TTime++)
	{
		for (i = 1; i <= M; i++)
		{
			if (tt[i][TTime] != 0)
			{
				setcolor(cococolor(tt[i][TTime]));
				setfillcolor(cococolor(tt[i][TTime]));
				if (tt[i][TTime - 1] != tt[i][TTime] && tt[i][TTime] != -1)
				{
					_stprintf_s(b, _T("%d"), tt[i][TTime] - 1);
					outtextxy(0.1 * size + 40 + TTime - 1, i * 50 - 12, b);
					_stprintf_s(b, _T("%d"), TTime - 1);
					outtextxy(0.1 * size + 40 + TTime - 1, i * 50 + 12, b);
				}
				else if (tt[i][TTime - 1] != tt[i][TTime])
				{
					TCHAR zxc[6] = _T("检修");
					outtextxy(0.1 * size + 40 + TTime - 1, i * 50 - 12, zxc);
					_stprintf_s(b, _T("%d"), TTime - 1);
					outtextxy(0.1 * size + 40 + TTime - 1, i * 50 + 12, b);
				}
				if (tt[i][TTime] != tt[i][TTime + 1])
				{
					_stprintf_s(b, _T("%d"), TTime);
					outtextxy(0.1 * size + 40 + TTime - 1 - 8, i * 50 + 12 + 12, b);
				}
				fillrectangle(0.1*size + 40 + TTime - 1, i * 50, 0.1*size + 40 + TTime, i * 50 + 9);
			}
		}
		Sleep(10);
	}
	settextstyle(16, 0, _T("宋体"));
	saveimage(_T("output1.bmp"), NULL);
	_getch();
	_getch();
	closegraph();
	for (i = 0; i <= M; i++)
	{
		free(MaTimeStart[i]);
		free(MaTimeStop[i]);
	}
	free(MaTimeStart);
	free(MaTimeStop);
	for (i = 0; i <= M; i++)
		Freestruct(result[i]);
	free(result);
}
COLORREF cococolor(int MM)
{
	if (MM == -1)return BLACK;
	else if (MM == 1)return RED;
	else if (MM == 2)return BLUE;
	else if (MM == 3)return YELLOW;
	else if (MM == 4)return GREEN;
	else if (MM == 5)return CYAN;
	else if (MM == 6)return MAGENTA;
	else if (MM == 7)return BROWN;
	else if (MM == 8)return LIGHTGRAY;
	else if (MM == 9)return LIGHTBLUE;
	else if (MM == 10)return DARKGRAY;
	else if (MM == 11)return LIGHTGREEN;
	else if (MM == 12)return LIGHTMAGENTA;
	else if (MM == 13)return LIGHTCYAN;
	else if (MM == 14)return LIGHTRED;
	else return LIGHTRED;
}



void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}