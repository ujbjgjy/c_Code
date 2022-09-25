#include "head.h"
void sort__(int(*card)[18]);

int main()
{
	srand(time(NULL));
	int card[3][18] = { 0 };
	//分牌
	rand_(card, sizeof(card) / sizeof(card[0][0]));
	//排序
	sort_(card);
	//打印
	print(card,-1);
	//抢地主
	int n=grab(card);//抢地主并返回谁是地主  
	//出牌
	play_cards(card, n);


	//printf("\n\n");
	//int i, j;
	//for ( i = 0; i < 3; i++)
	//{
	//	for ( j = 0; j < 18; j++)
	//	{
	//		printf("%d ", card[i][j]);
	//	}
	//}
	return 0;
}

void sort__(int(*card)[18])
{
	int arr[54]={0};
	int i, j,k=0;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 18; j++)
		{
			arr[k] = card[i][j];
			++k;
		}
	}
	for (i = 0; i < 54 - 1; i++)
	{
		for ( k = 0;  k < 54-1-i; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				int tmp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = tmp;
			}
		}
	}
	k = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 18; j++)
		{
			card[i][j] = arr[k];
			k++;
		}
	}
}