#include "head.h"

int main()
{
	srand(time(NULL));
	int card[PEOPEL][CARDNUM] = { 0 };
	memset(card, 0, sizeof(card));
	//分牌
	rand_(card, 54);
	//打印
	print(card,-1);
	//抢地主
	int n=grab(card);//抢地主并返回谁是地主  
	//玩家出牌
	play_cards(card, n);
	
	printf("\n\n");
	//int i, j;
	//for ( i = 0; i < 3; i++)
	//{
	//	for ( j = 0; j < 20; j++)
	//	{
	//		printf("%2d ", card[i][j]);
	//	}
	//	printf("\n");
	//}

	return 0;
}