#include "head.h"

int main()
{
	srand(time(NULL));
	int card[PEOPEL][CARDNUM] = { 0 };
	memset(card, 0, sizeof(card));
	//����
	rand_(card, 54);
	//��ӡ
	print(card,-1);
	//������
	int n=grab(card);//������������˭�ǵ���  
	//��ҳ���
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