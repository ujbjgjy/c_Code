#include "header.h"

void Print(const int(*ps)[NUMBER][LINE][COLUMN],int sum)//打印地图
{
	int i=0, j=0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if ((*ps)[sum][i][j] == cle)
				printf("  ");
			else
				printf("%d ", (*ps)[sum][i][j]);
		}
		printf("\n");
	}
}

int Operation(int(*ps)[NUMBER][LINE][COLUMN])//执行游戏操作
{
	int sum = 0;//当前关卡
	int i = 0, j = 0;
	if(Location(ps, sum, &i, &j)) return -1;

	int iput = 1;
	while (iput!=27||iput!=-1)
	{
		char mob = getch();
		iput = mob;
		switch (mob)
		{
		case 'h':
		case 72:
			if ((*ps)[sum][i - 1][j] == cle || (*ps)[sum][i - 1][j] == tar)//前面1空地或目标
			{
				(*ps)[sum][i - 1][j] += fig;//前面1空地目标+人物
				(*ps)[sum][i][j] -= fig;//原位-人物
				--i;
			}
			else if ((*ps)[sum][i - 1][j] == box || (*ps)[sum][i - 1][j] == box + tar)//前面是箱子或箱子+目标
			{
				if ((*ps)[sum][i - 2][j] != wall && (*ps)[sum][i - 2][j] != box && (*ps)[sum][i - 2][j] != box)//前面不能是墙和箱子
				{
					(*ps)[sum][i - 2][j] += box;
					(*ps)[sum][i - 1][j] = (*ps)[sum][i - 1][j]-box+fig;
					(*ps)[sum][i][j] -= fig;
					--i;
				}
			}
			break;
		case 'l':
		case 80:
			if ((*ps)[sum][i + 1][j] == cle || (*ps)[sum][i + 1][j] == tar)//前面1空地或目标
			{
				(*ps)[sum][i + 1][j] += fig;//前面1空地目标+人物
				(*ps)[sum][i][j] -= fig;//原位-人物
				++i;
			}
			else if ((*ps)[sum][i + 1][j] == box || (*ps)[sum][i + 1][j] == box + tar)//前面是箱子或箱子+目标
			{
				if ((*ps)[sum][i + 2][j] != wall && (*ps)[sum][i + 2][j] != box && (*ps)[sum][i + 2][j] != box+tar)//前面不能是墙和箱子
				{
					(*ps)[sum][i + 2][j] += box;
					(*ps)[sum][i + 1][j] = (*ps)[sum][i + 1][j] - box + fig;
					(*ps)[sum][i][j] -= fig;
					++i;
				}
			}
			break;
		case 'j':
		case 75:
			if ((*ps)[sum][i][j - 1] == cle || (*ps)[sum][i][j - 1] == tar)//前面1空地或目标
			{
				(*ps)[sum][i][j - 1] += fig;//前面1空地目标+人物
				(*ps)[sum][i][j] -= fig;//原位-人物
				--j;
			}
			else if ((*ps)[sum][i][j - 1] == box || (*ps)[sum][i][j - 1] == box + tar)//前面是箱子或箱子+目标
			{
				if ((*ps)[sum][i][j - 2] != wall && (*ps)[sum][i][j - 2] != box && (*ps)[sum][i][j - 2] != box + tar)//前面不能是墙和箱子
				{
					(*ps)[sum][i][j - 2] += box;
					(*ps)[sum][i][j - 1] = (*ps)[sum][i][j - 1] - box + fig;
					(*ps)[sum][i][j] -= fig;
					--j;
				}
			}
			break;
		case 'k':
		case 77:
			if ((*ps)[sum][i][j + 1] == cle || (*ps)[sum][i][j + 1] == tar)//前面1空地或目标
			{
				(*ps)[sum][i][j + 1] += fig;//前面1空地目标+人物
				(*ps)[sum][i][j] -= fig;//原位-人物
				++j;
			}
			else if ((*ps)[sum][i][j + 1] == box || (*ps)[sum][i][j + 1] == box + tar)//前面是箱子或箱子+目标
			{
				if ((*ps)[sum][i][j + 2] != wall && (*ps)[sum][i][j + 2] != box && (*ps)[sum][i][j + 2] != box + tar)//前面不能是墙和箱子
				{
					(*ps)[sum][i][j + 2] += box;
					(*ps)[sum][i][j + 1] = (*ps)[sum][i][j + 1] - box + fig;
					(*ps)[sum][i][j] -= fig;
					++j;
				}
			}
			break;
		}

		system("cls");
		if (!check(ps,sum))
		{
			if (sum < NUMBER)
			{
				++sum;
				if (Location(ps, sum, &i, &j)) return -1;//每升一关重新找坐标
			}
			else
			{
				return 1;
			}
		}
		Print(ps, sum);
	}

	if (iput == 27)
		return 0;
	else
		return 1;
}

int check(int(*ps)[NUMBER][LINE][COLUMN],int sum)//检查有没有箱子
{
	int i = 0, j = 0;
	int cost = 0;//计算多少个箱子
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if ((*ps)[sum][i][j] == box)
				cost++;
		}
	}
	return cost;
}

int Location(const int(*ps)[NUMBER][LINE][COLUMN], int sum, int* x, int* y)//找到人物坐标
{
	int i = 0, j = 0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if ((*ps)[sum][i][j] == fig || (*ps)[sum][i][j] == fig + tar)
				break;
		}
		if ((*ps)[sum][i][j] == fig || (*ps)[sum][i][j] == fig + tar)
			break;
	}
	if ((*ps)[sum][i][j] != fig && (*ps)[sum][i][j] != fig + tar)
	{
		return 1;
	}
	else
	{
		*x = i, *y = j;
		return 0;
	}
}