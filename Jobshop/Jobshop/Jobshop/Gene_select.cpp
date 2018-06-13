#include"jobhead.h"
void Roulette()
{
	int FitAll = 0;
	int i, j;
	for (i = 1; i<chronum; i++)
		FitAll += FitFather[i];
	for (i = 1; i<Nextgen; i++)
		FitAll += FitSon[i];
	int foot;
	int key = 0;
	int	finish;
	
	for (finish = 1; finish<chronum; finish++)
	{
		foot = rand() % FitAll + 1;
		key = 0;
		for (i = 1; i<chronum&&key == 0; i++)
		{
			if (foot>FitFather[i])
			{
				foot -= FitFather[i];
			}
			else
			{
				key = 1;
				if (generation % 2 == 1)
					for (j = 0; j <= ProcedureTotal; j++)
						ChroTwo[finish][j] = ChroOne[i][j];
				else
					for (j = 0; j <= ProcedureTotal; j++)
						ChroOne[finish][j] = ChroTwo[i][j];
			}
		}
		for (i = 1; i<Nextgen&&key == 0; i++)
		{
			if (foot>FitSon[i])
			{
				foot -= FitSon[i];
			}
			else
			{
				key = 1;
				if (generation % 2 == 1)
					for (j = 0; j <= ProcedureTotal; j++)
						ChroTwo[finish][j] = ChroSon[i][j];
				else
					for (j = 0; j <= ProcedureTotal; j++)
						ChroOne[finish][j] = ChroSon[i][j];
			}
		}
	}

}
void Fitness()
{
	int i;
	average = 0;
	if (generation % 2 == 1)
	{
		for (i = 1; i<chronum; i++)
		{
			FitFather[i] = ChroOne[i][0] - 0.8*GreatGeneNum;
			FitFather[i] = 100 * GreatGeneNum / (FitFather[i] + 1);

			average += ChroOne[i][0];
		}
	}
	else
	{
		for (i = 1; i<chronum; i++)
		{
			FitFather[i] = ChroTwo[i][0] - 0.8*GreatGeneNum;
			FitFather[i] = 100 * GreatGeneNum / (FitFather[i] + 1);
			average += ChroTwo[i][0];
		}
	}
	for (i = 1; i<Nextgen; i++)
	{
		FitSon[i] = ChroSon[i][0] - 0.8*GreatGeneNum;
		FitSon[i] = 100 * GreatGeneNum / (FitSon[i] + 1);
	}
	average /= (chronum - 1);
}
void Championships()
{
	int temp;
	int finish;
	int i;
	int tempchamgrade;
	int tempchamnum;
	int tempgrade;
	int all = chronum + Nextgen - 1;;
	if (generation % 2 == 1)
	{
		for (finish = 1; finish<chronum; finish++)
		{
			tempchamgrade = 0;
			tempchamnum = 0;
			for (i = 1; i<chronum / 2; i++)
			{
				temp = rand() % (all - 1) + 1;
				if (temp >= chronum)
					tempgrade = ChroSon[temp - chronum + 1][0];
				else
					tempgrade = ChroOne[temp][0];
				if (tempchamnum == 0)
				{
					tempchamnum = temp;
					tempchamgrade = tempgrade;
				}
				else if (tempgrade<tempchamgrade)
				{
					tempchamnum = temp;
					tempchamgrade = tempgrade;
				}
			}

			if (temp >= chronum)
			{
				for (i = 0; i <= ProcedureTotal; i++)
					ChroTwo[finish][i] = ChroSon[temp - chronum + 1][i];
			}
			else
			{
				for (i = 0; i <= ProcedureTotal; i++)
					ChroTwo[finish][i] = ChroOne[temp][i];
			}
		}
	}
	else
	{
		for (finish = 1; finish<chronum; finish++)
		{
			tempchamgrade = 0;
			tempchamnum = 0;
			for (i = 1; i<chronum / 2; i++)
			{
				temp = rand() % (all - 1) + 1;
				if (temp >= chronum)
					tempgrade = ChroSon[temp - chronum + 1][0];
				else
					tempgrade = ChroOne[temp][0];
				if (tempchamnum == 0)
				{
					tempchamnum = temp;
					tempchamgrade = tempgrade;
				}
				else if (tempgrade<tempchamgrade)
				{
					tempchamnum = temp;
					tempchamgrade = tempgrade;
				}
			}

			if (temp >= chronum)
			{
				for (i = 0; i <= ProcedureTotal; i++)
					ChroOne[finish][i] = ChroSon[temp - chronum + 1][i];
			}
			else
			{
				for (i = 0; i <= ProcedureTotal; i++)
					ChroOne[finish][i] = ChroTwo[temp][i];
			}
		}
	}
	return;
}