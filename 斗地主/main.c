#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int check_rand(int(*card)[], int i)
{
	int number = i;
	while (i)
	{
		if ((*card)[i - 1] == (*card)[number])
		{
			return 0;
		}
		else
		{
			i--;
		}
	}
	return 1;
}

void random(int(*card)[])
{
	int i = 0;
	for (i = 0; i < 54;)
	{
		(*card)[i] = rand() % 54;
		if (check_rand(card, i)) i++;
	}
}

void print_card(int (*card)[],char* peopel)
{
	int i = 0, k = 0;
	for (i = 0; i < 54; i++)
	{
		if (i % 18 == 0) printf("\n%c:	",*(peopel++));
		printf("%2d ", (*card)[i]);
	}
}

void sort_(int(*card)[])
{
	int i = 0, j = 0;



}

int main()
{
	char people[4] = "abc";
	int card[54] = { 0 };
	srand(time(NULL));
	random(&card);

	sort_(&card);

	print_card(&card, people);


	return 0;
}