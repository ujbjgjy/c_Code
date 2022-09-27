#include "head.h"


//分牌
static int check_rand(int (*card)[CARDNUM],int l,int r)
{
	if ((l + r) == 0) return 1;

	int i = 0, j = 0;
	for ( i = 0; i <= l; i++)
	{
		for (j = 0; j <= CARDNUM-2-1; j++)//一行所有的牌数
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
void rand_(int (*card)[CARDNUM], int sum)
{
	int i = 0, j = 0;

	for (i = 0; i < PEOPEL; i++)
	{
		for (j = 0; j < CARDNUM-2; )
		{
			card[i][j] = rand() % sum + 1;
			if(check_rand(card, i, j))
				j++;
		}
	}
}

//排序
void sort_(int(*card)[CARDNUM])
{
	int i, j, k;

	for ( i = 0; i < PEOPEL; i++)
	{
		for ( j = 0; j < CARDNUM-1; j++)
		{
			for ( k = 0; k < CARDNUM-1-j; k++)
			{
				if (card[i][k + 1] != 0)
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
static void judge(int (*card)[CARDNUM],int landlord)
{
	if (landlord == -1) return;
	if (landlord == 0)
	{
		card[landlord][CARDNUM - 2] = card[1][CARDNUM - 3];
		card[landlord][CARDNUM - 1] = card[2][CARDNUM - 3];
		card[1][CARDNUM - 3] = 0;
		card[2][CARDNUM - 3] = 0;
	}
	else if (landlord == 1)
	{
		card[landlord][CARDNUM - 2] = card[0][CARDNUM - 3];
		card[landlord][CARDNUM - 1] = card[2][CARDNUM - 3];
		card[0][CARDNUM - 3] = 0;
		card[2][CARDNUM - 3] = 0;
	}
	else
	{
		card[landlord][CARDNUM - 2] = card[0][CARDNUM - 3];
		card[landlord][CARDNUM - 1] = card[1][CARDNUM - 3];
		card[0][CARDNUM - 3] = 0;
		card[1][CARDNUM - 3] = 0;
	}
	return;
}//判断是否是地主
static void wire()
{
	printf("\n");
	int i = 60;
	while (i--) printf("=");
	printf("\n");
}
void print(int(*card)[CARDNUM], int landlord)
{
	sort_(card);
	int i = 0, j = 0;
	for ( i = 0; i < PEOPEL; i++)
	{
		print_people(i, landlord);
		for ( j = 0; j < CARDNUM; j++)
		{
			if (card[i][j] != 0)
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
		}
	}
	wire();
}

//抢地主
int grab(int(*card)[CARDNUM])
{
	printf("是否抢地主y/n==>");
	char ch = 0;
	scanf("%c", &ch);
	if (ch == 'y')
	{
		system("cls");
		judge(card, 0);
		print(card, 0);
		return 0;
	}
	else
	{
		system("cls");
		int tmp = rand() % 2 + 1;
		judge(card, tmp);
		print(card, tmp);
		return tmp;
	}
}

//玩家出牌
static void Input(int (*card)[CARDNUM],char* arr,int n)
{
	int num = strlen(arr);
	int* order = malloc(sizeof(int) * num);
	if (n >= 0)//为地主
	{
		if (num > CARDNUM)
		{
			return;
		}
		else
		{
			int i = 0;
			for ( i = 0; i < num; i++)
			{
				sscanf(arr[i], "%d", order[i]);
				printf("%d ", card[n][order[i]]);
			}
			printf("\n");
		}
	}
	else//不是地主
	{
		if (num > CARDNUM - 3)
		{
			return;
		}
		else
		{
			int i = 0;
			for (i = 0; i < num; i++)
			{
				sscanf(arr[i], "%d", order[i]);
				printf("%d ", card[n][order[i]]);
			}
			printf("\n");
		}
	}
	if (order != NULL)
		free(order);
	return;
}
void play_cards(int(*card)[CARDNUM], int n)
{
	if (n == 0)//自己为地主的话
	{
		printf("A:");
		char arr[CARDNUM+1] = { 0 };
		scanf("%s", arr);
		Input(card, arr, n);
	} 
}