#include <stdio.h>
#include <string.h>

typedef struct SNAKE
{
	int x;
	int y;//��ͷ�ĵ�ǰ����


}SNAKE;


void print(const char(*arr)[25])
{
	int i = 0;
	for (i = 0; i < 25; i++)
	{
		printf("%c", (*arr)[i]);
	}
}

void right()
{

}

int main()
{
	char arr[25] = { 0 };
	memset(arr, ' ', sizeof(arr));


	
	right(&arr);
	print(&arr);
	printf("\n");
	return 0;
}
