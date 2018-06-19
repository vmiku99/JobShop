#include"jobhead.h"
int input()
{
	char a[501];
	int i, j;
	int y;
	int flag;
	int num;
	while (1)
	{
		gets_s(a);
		if (a[0] >= '0'&&a[0] <= '9')break;
	}
	for (i = 1; i <= N + 1; i++)
	{
		num = 0;
		flag = 1;
		if (i != 1)gets_s(a);
		y = strlen(a);
		for (j = 0; j<y; j++)
		{
			if (a[j] == '(')
			{
				num = 0;
			}
			else if (a[j] == ',')
			{
				Ti[i][flag] = num;
				num = 0;
			}
			else if (a[j] == ')')
			{
				Ma[i][flag] = num;
				flag++;
				n_num[i]++;
				ProcedureTotal++;
				num = 0;
			}
			else if (a[j] >= '0'&&a[j] <= '9')
			{
				num = num * 10 + a[j] - '0';
			}
			else continue;
		}
	}
	return 0;
}
int input2()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf_s("%d%d", &Ma[i][j], &Ti[i][j]);
			Ma[i][j]++;
			n_num[i]++;
			ProcedureTotal++;
		}
	}
	return 0;
}