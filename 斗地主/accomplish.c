#include "head.h"


//分牌
static int check_rand(int (*card)[18],int l,int r)
{
	if ((l + r) == 0) return 1;

	int i = 0, j = 0;
	for ( i = 0; i <= l; i++)
	{
		for (j = 0; j <= 17; j++)
		{
			if ((i == l) && (j == r))
			{
				return 1;
			}
			else
			{
				if (card[i][j] == card[l][r])
					return 0;
			}
		}
	}
	return 1;
}//检查rand是否有重复的,
void rand_(int (*card)[18], int sum)
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 18; )
		{
			card[i][j] = rand() % sum + 1;
			if(check_rand(card, i, j))
				j++;
		}
	}
}

//排序
void sort_(int(*card)[18])
{
	int i, j, k;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 18 - 1; j++)
		{
			for (k = 0; k < 18 - 1 - j; k++)
			{
				if (card[i][k] > card[i][k + 1])
				{
					int tmp = card[i][k];
					card[i][k] = card[i][k + 1];
					card[i][k + 1] = tmp;
				}
			}
		}
	}
}

//打印
static void print_people(int i,int landlord)
{
	if (i == 1 || i == 2) printf("\n\n");
	if (i == landlord)
	{
		printf("地主\n");
		printf("%c:", 65 + i);
	}
	else
	{
		printf("%c:", 65 + i);
	}
}//打印每个数组相对应的玩家
static void judge(int (*card)[18],int i,int landlord)
{
	if (landlord == -1 || landlord > 2) return;

	if (i == landlord)
	{
		int k = 0;
		while (k != 3)
		{
			if (i == 0)
			{
				printf("%2d ", card[k][17]);
			}
			else
			{
				printf("%2c ", '#');
			}
			k++;
		}
	}
	return;
}//判断是否是地主
void print(int(*card)[18], int landlord)
{
	int i = 0, j = 0;

	for ( i = 0; i < 3; i++)
	{
		print_people(i, landlord);
		for (j = 0; j < 17; j++)
		{
			if (i == 0)
			{
				printf("%2d ", card[i][j]);
			}
			else
			{
				printf("%2c ", '#');
			}
		}
		judge(card, i, landlord);
	}
}

//抢地主
static void wire()
{
	printf("\n");
	int i = 80;
	while (i--) printf("=");
	printf("\n");
}
int grab(int(*card)[18])
{
	wire();
	printf("是否抢地主y/n==>");
	char ch = 0;
	scanf("%c", &ch);
	if (ch == 'y')
	{
		system("cls");
		print(card, 0);
		return 0;
	}
	else
	{
		system("cls");
		int tmp = rand() % 2 + 1;
		print(card, tmp);
		return tmp;
	}
}

//出牌
void play_cards(int(*card)[8], int n)
{
	;
}