#include <stdio.h>

int main()
{
	int i = 1;

	if (1 == *(char*)&i)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;
}